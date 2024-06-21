#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"


Graph::Graph()
{
    // each node mapped to a unique value between 0 and 11
    for(int i=0; i<36; i++){
        dict[nodes[i]] = i;
    }
    // reading data from 'graph.txt' file
    string line1, src, dest;
	ifstream file("Map.txt");
	while(getline(file, line1)){
        // processing data line by line
        // each line represents one edge: (src, dest, weight)
        int pos = 1;
        int counter = 2;
        string word = "";
        while(counter != 0){
            char x = line1[pos];
            if(x ==','){
                if(counter == 2){
                    src = word;
                } else {
                    dest = word;
                }
                counter--;
                word = "";
            }else{
                word += x;
            }
            pos++;
        }
        string cost = line1.substr(pos,line1.length()-1);
        // string to int conversion
        int weight = stoi(cost);
        // add edge to graph
        this->addEdge(src, dest, weight);
    }
}

void Graph::addEdge(string start, string end, int cost)
{
    int v1 = dict[start];
    int v2 = dict[end];
    // add edge from src to dest
    Edge newEdge(start, end, cost);
    arr[v1].insert_at_tail(newEdge);
    // add edge from dest to src (undirected graph)
    Edge newEdge2(end, start, cost);
    arr[v2].insert_at_tail(newEdge2);
}
void Graph::display()
{
    for(int i=0; i<36; i++){
        Node* temp = arr[i].head;
        while(temp!=NULL){
            cout<<"("<<temp->e.src<<", "<<temp->e.dest<<", "<<temp->e.weight<<")"<<endl;
            temp = temp->next;
        }
        cout<<endl<<"_______________________________"<<endl;
    }
}

bool Graph::Reachable(string start, string end)
{ // This function uses bfs to check availability of a path between the two nodes
	vector<int> visited;
	for(int i=0; i<36; i++){
		visited.push_back(0);
	}
	queue<Edge> Q;
	int x = dict[start];
    // loop through nodes adjacent to source node
    Node* temp = arr[x].head;
	while(temp!=NULL){
        // check if it is the destination node
        if(temp->e.dest == end){
            return true;
        }
        // add edges to queue
		Q.push(temp->e);
        temp=temp->next;
	}
    // mark source node as visited
	visited[x] = 1;
	while(!Q.empty()){
        // pop front edge from the queue
		Edge edge = Q.front();
		Q.pop();
		string value = edge.dest;
		int x = dict[value];
        // loop thorugh adjacent nodes
        Node* temp = arr[x].head;
        while(temp!=NULL){
            if(temp->e.dest == end){
                return true;
            }
            int y = dict[temp->e.dest];
            // add edges if the adj node is unvisited
            if(!visited[y]){
                Q.push(temp->e);
            }
            temp=temp->next;
        }
        // mark visited
		visited[x] = 1;
	}
    // no path available
	return false;
}

pair<int, string> Graph::Dijkstra(string start, string dest)
{// This function uses Dijkstra's algorithm to find the shortest path between the two nodes
	
    // initialise cost to all nodes as INT_MAX
    vector<int> D;
	for(int i=0; i<36; i++){
		D.push_back(__INT_MAX__);
	}

	vector<bool> known; // nodes to whom the shortest path is known
	for(int i=0; i<36; i++){
		known.push_back(false);
	}

    // create minimum heap
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater_equal<pair<int, string>>> min_heap;
    // insert source vector into min_heap with distance as 0
	min_heap.push(make_pair(0, start));

	while(!min_heap.empty()){
        // minimum cost node extracted 
		pair<int, string> p_i = min_heap.top();
		min_heap.pop();
        string path_dest = "";
        if(!p_i.second.find("."))
            path_dest = p_i.second;
        else {
            for(int i=0; i<p_i.second.length(); i++){
                if(p_i.second[i] == '.')
                    break;
                path_dest += p_i.second[i]; 
            }
        }
        // check if it is the destination node
		if(path_dest == dest){
			return p_i;
		}
		int index = dict[path_dest];
		D[index] = p_i.first;
        // mark shortest path to this node as known
		known[index] = true;
        // check adjacent nodes
        Node* temp = arr[index].head;
        while(temp!=NULL){
            int i = dict[temp->e.dest];
            if(!known[i]){
                if(D[i] > D[index] + temp->e.weight){
                    // update cost to adjacent nodes if lesser cost path available
                    D[i] = D[index] + temp->e.weight;
                    min_heap.push(make_pair(D[i], temp->e.dest+"."+p_i.second));
                }
            }
            temp=temp->next;
        }
	}
    return make_pair(0, "");
}

#endif