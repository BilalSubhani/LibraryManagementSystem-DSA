#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    string src;
    string dest;
    int weight;

//Default constructor
    Edge(){};
//Parameterized constructor
    Edge(string s, string d, int w)
    {
        src = s;
        dest = d;
        weight = w;
    }
};

class Node
{
public: 
    Edge e;
    Node* next;
//Constructor
    Node(Edge edge)
    {
        this->e = edge;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;
    Node* tail;

//Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_tail(Edge edge) // adds a new node at the tail of the linked list
    {
        Node* newNode = new Node(edge);
        if(!tail){
            tail = newNode;
            head = tail;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

class Graph
{
public:
    LinkedList arr[36];
    unordered_map <string, int> dict;
    string nodes[36] = {"A Block Model Town", "H Block Model Town", "G Block Model Town", "F Block Model Town", "E Block Model Town",
                         "D Block Model Town", "C Block Model Town", "B Block Model Town", "A Block Gulberg", "B Block Gulberg", "C Block Gulberg", "D Block Gulberg", 
                         "E Block Gulberg", "F Block Gulberg", "G Block Gulberg", "H Block Gulberg", "I Block Gulberg", "J Block Gulberg", "K Block Gulberg", 
                         "L Block Gulberg", "A Block Garden Town", "B Block Garden Town", "C Block Garden Town", "D Block Garden Town", "E Block Garden Town", 
                         "F Block Garden Town", "G Block Garden Town", "H Block Garden Town", "I Block Garden Town", "J Block Garden Town", "K Block Garden Town", 
                         "L Block Garden Town", "A Block Faisal Town", "B Block Faisal Town", "C Block Faisal Town", "D Block Faisal Town"};

// Constructor
    Graph();
// Functions
	void addEdge(string start, string end, int weight); // adds an edge to the graph given the start/src, end/dest, and weight
    void display(); // displays all the edges in the graph
    bool Reachable(string src, string dest); // returns true if a path from src to dest is available
    pair<int, string> Dijkstra(string start, string dest); // computes the shortest path between two nodes

};

#endif
