#include <iostream>
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "Graph.cpp"
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

class borrower{
public:
	string cnic;
	string name;
	string mobileNumber;
	string address;

	borrower(string c, string n, string m, string a){
		cnic = c;
		mobileNumber = m;
		name = n;
		address = a;
	}
};

class book{
public:
	string title;
	string author;
	string edition;
	string publisher;
	string issueStatus;
	string issueDate;
	string returnDate;
	string borrowerCNIC;

	book(string t, string a, string e, string p, string is, string id, string rd, string b){
		title = t;
		author = a;
		edition = e;
		publisher = p;
		issueStatus = is;
		issueDate = id;
		returnDate = rd;
		borrowerCNIC = b;
	}
};
typedef unordered_multimap<int, book>::iterator idit;
typedef unordered_multimap<string, int>::iterator SIit;
typedef set<string, greater<string> >::iterator BSTit;
typedef unordered_multimap <string, borrower>::iterator Borrower_it;
void printID(unordered_multimap<int, book> umm)
{
    idit it = umm.begin();
    for (; it != umm.end(); it++){
		cout <<"Book id: "<<it->first<<"\n"<<"Title:" << it->second.title<<" | Author: "<<it->second.author<<" | Edition: "<<it->second.edition<<" | Status: "<<it->second.issueStatus << "\n\n";
	}
    cout << endl;
}

/* run this program using the console pauser or add your own getch, 
//    system("pause") or input loop */

int BOOK_ID = 0;

Graph G;
unordered_multimap <int, book> id;
unordered_multimap <string, int> title;
unordered_multimap <string, int> author;
unordered_multimap <string, borrower> borrowers;
set <string, greater<string>> bst;

string LIBRARY_ADDRESS = "G Block Model Town";

int main(int argc, char** argv) 
{
	// read csv and load all books
	vector<string> row;
    string line, word, temp;
	
	fstream file;
	file.open("Books.csv", ios::in);
    while (getline(file, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
			row.push_back(word);
		}

		book B(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
		id.insert(make_pair(BOOK_ID, B));
		title.insert(make_pair(row[0], BOOK_ID));
		author.insert(make_pair(row[1], BOOK_ID));
		BOOK_ID++;
	}
           

	int outerChoice = 0;
	while(outerChoice!=9){
		// system("cls");
		cout<<"\n Library Management Version 1.0 \n\n";
		cout<<"\n1. Admin";
		cout<<"\n2. User";
		cout<<"\n9. Exit"; 
		cout<<"\n\nEnter your choice : ";
		cin>>outerChoice;
		
		if( outerChoice == 1 )
		{
			char adminUser[10];
			char adminPassword[10];
			
			// system("cls");
			cout<<"\n ---------- Admin Login -------";
			cout<<"\n\n Enter username: ";
			cin>>adminUser;
			cout<<"\n Enter password:";
			cin>>adminPassword;
			if( (strcmp(adminUser, ADMINUSER) == 0) && 
				( strcmp(adminPassword, ADMINPASSWORD) == 0)){
				
				getchar();
				// system("cls");
				int innerChoice = 0;
				while(innerChoice != 9)
				{
					cout<<"\n\n Admin Login is Successful !! Press any key to continue..";	
					cout<<"\n1. Add Book";
					cout<<"\n2. Update Book";
					cout<<"\n3. Delete Book";
					cout<<"\n4. List of All Books";
					cout<<"\n5. Search by title";
					cout<<"\n6. Search by author";
					cout<<"\n9. Exit";
					cout<<"\n\n Enter your choice : ";
					cin>>innerChoice;
						switch(innerChoice){
						case 1: addBook(); break;
						case 2: updateBook(); break;
						case 3: deleteBook(); break;
						case 4: listOfAllBooks(); break;
						case 5: searchByTitle(); break;
						case 6: searchByAuthor(); break;
						default: cout<<"\n\n Invalid Choice. Press any key to continue..";
								getchar();
					}
					// system("cls");
				}
			}
			else
			{
				cout<<"\n\n Error : Invalid Credentials. Press any key to conitnue";
				getchar(); getchar();
			}			
		}
		else if(outerChoice ==2) 
		{			    
			char studentUser[10];
			char studentPassword[10];
				
			// system("cls");
			cout<<"\n ---------- Student Login -------";
			cout<<"\n\n Enter username: ";
			cin>>studentUser;
			cout<<"\n Enter password:";
			cin>>studentPassword;
				
			if( (strcmp(studentUser, USER) ==0)  && 
				(strcmp(studentPassword, USERPASSWORD) == 0)){
				int innerChoice = 0;
				while(innerChoice != 9){
					// system("cls");
					cout<<"\n1. Borrow a Book";
					cout<<"\n2. Return a Book";
					cout<<"\n3. List of All Books";
					cout<<"\n4. Search by title";
					cout<<"\n5. Search by author";
					cout<<"\n9. Exit";  
					cout<<"\n\n Enter your choice : ";
					cin>>innerChoice; 	
					
					switch(innerChoice){
						case 1: borrowBook();break;
						case 2: returnBook();break;
						case 3: listOfAllBooks(); break;
						case 4: searchByTitle(); break;
						case 5: searchByAuthor(); break;
						case 9: break;
						default: cout<<"\n\n Error: Invalid Choice. Press any key to continue..";
						getchar();getchar();
					}
					
				}
				// system("cls");
			}
			else
			{
			cout<<"\n\n Error : Invalid Credentials. Press any key to conitnue";
			getchar();getchar();
				
			}
		}
		else if(outerChoice!=9){
			cout<<"\n\n Invalid choice. Press any key to continue..";
			// getchar();getchar(); //put system sleep and cls
		}
		else
		{
			cout<<"\n\n Thank you for using it !! Press any key to exit";
			getchar();getchar();
		}
	}

	return 0;
}

int addBook(){
	string bookname;
	string bookauthor;
	string edition;
	string publisher;


	// system("cls");
	cout<<"\n ---- Add a new Book ----";

	cout<<"\n Enter book name : ";
	cin>>bookname;
	cout<<"\n Enter book author : ";
	cin>>bookauthor;
	cout<<"\n Enter edition: ";
	cin>>edition;
	cout<<"\n Enter publisher name: ";
	cin>>publisher;


	// append to data structure
	book B(bookname, bookauthor, edition, publisher, "Not Issued", "Nill", "Nill", "Nill");

	BOOK_ID++;

	// write to csv file the the newly created book
	fstream file;
	file.open("Books.csv", ios::app);

	file<<bookname<<",";
	file<<bookauthor<<",";
	file<<edition<<",";
	file<<publisher<<",";
	file<<"Not Issued"<<",";
	file<<"Nill"<<",";
	file<<"Nill"<<",";
	file<<"Nill"<<"\n";

	file.close();

	cout<<"\n File Saved Successfully!!";
	getchar(); getchar();
	return 0;	
}

int deleteBook(){
	int ID;
	cout<<"Enter the book ID of book to delete: ";
	cin>>ID;
	cout<<endl;
	idit it = id.find(ID);
	if(it != id.end()){
		if(it->second.issueStatus == "Not Issued"){
			SIit it2 = title.begin();
			for (; it2 != title.end(); it2++){
				if(it2->second == it->first){
					title.erase(it2->first);
				}
			}
			it2 = author.begin();
			for (; it2 != author.end(); it2++){
				if(it2->second == it->first){
					author.erase(it2->first);
				}
			}
			id.erase(it->first);
		} else {
			cout<<"Book is already issued. You can delete once it is returned."<<endl;
		}
	} else {
		cout<<"Book with ID doesnot exist."<<endl;
	}

	return 0;
}

int updateBook(){
	// update book details in data structure
	// update csv
	return 0;
}

int listOfAllBooks(){
	// display all books using data structure
	printID(id);
	return 0;
}

int borrowBook(){
	string cnic;
	string name;
	string mobile;
	string address;

	cin.ignore();
	cout<<"Enter CNIC: ";
	getline(cin, cnic);
	cout<<"Enter name: ";
	getline(cin, name);
	cout<<"Enter mobile: ";
	getline(cin, mobile);
	cout<<"Enter address: (e.g 'A Block Gulberg' or 'C Block Garden Town')";
	getline(cin, address);

	int year, month, day;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	year = tm.tm_year + 1900;
	month = tm.tm_mon +1;
	day = tm.tm_mday;
	string issueDate = to_string(day)+"/"+to_string(month)+"/"+to_string(year);


	int ID;
	cout<<"Enter the book ID of book you want to borrow: ";
	cin>>ID;
	cout<<endl;
	idit it = id.find(ID);
	if(it != id.end()){
		if(it->second.issueStatus == "Not Issued"){
			it->second.issueStatus = "Issued";
			it->second.issueDate = issueDate;
			// for checking purposes return date same... else can add to days
			it->second.returnDate = issueDate;
			it->second.borrowerCNIC = cnic;
		} else {
			cout<<"We're sorry. Book already issued."<<endl;
		}
	} else {
		cout<<"Book with ID doesnot exist."<<endl;
	}

	pair<int, string> p = G.Dijkstra(LIBRARY_ADDRESS, address);
	cout<<"SHORTEST PATH FOR DELIVERY: "<<p.second<<endl<<endl;
	cout<<"COST FOR DELIVERY: "<<p.first<<endl<<endl;

	borrower B(cnic, name, mobile, address);
	bst.insert(cnic);
	borrowers.insert(make_pair(cnic, B));
	
	return 0;
	
}

int returnBook(){
	int year, month, day;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	year = tm.tm_year + 1900;
	month = tm.tm_mon +1;
	day = tm.tm_mday;

	string today = to_string(day)+"/"+to_string(month)+"/"+to_string(year);

	string cnic;
	string name;
	string mobile;
	string address;

	cin.ignore();
	cout<<"Enter CNIC: ";
	getline(cin, cnic);

	BSTit it3 = bst.find(cnic);
	if(it3 == bst.end()){
		cout<<"You have no books issued to you. Have a nice day!"<<endl;
		return 0;
	} else {
		Borrower_it it2 = borrowers.find(*it3);
		cout<<"Welcome back, "<<it2->second.name<<endl;
	}

	int ID;
	cout<<"Enter the book ID of book you want to return: ";
	cin>>ID;
	cout<<endl;
	idit it = id.find(ID);
	if(it != id.end()){
		if(it->second.issueStatus == "Issued" && it->second.borrowerCNIC==cnic){
			stringstream s1(it->second.returnDate);
			string dd1, mm1, yy1;
			getline(s1, dd1, '/');
			getline(s1, mm1, '/');
			getline(s1, yy1, '/');
			int d1, m1, y1;
			d1 = stoi(dd1);
			m1 = stoi(mm1);
			y1 = stoi(yy1);
			stringstream s2(today);
			string dd2, mm2, yy2;
			getline(s2, dd2, '/');
			getline(s2, mm2, '/');
			getline(s2, yy2, '/');
			int d2, m2, y2;
			d2 = stoi(dd2);
			m2 = stoi(mm2);
			y2 = stoi(yy2);
			if(y2 > y1){
				cout<<"LATE RETURN WARNING"<<endl;
			} else if(y2 == y1){
				if(m2>m1){
					cout<<"LATE RETURN WARNING"<<endl;
				} else if(m2==m1){
					if(d2>d1){
						cout<<"LATE RETURN WARNING"<<endl;
					}
				}
			}
			it->second.issueStatus = "Not Issued";
			it->second.issueDate = "Nill";
			it->second.returnDate = "Nill";
			it->second.borrowerCNIC = "Nill";
		} else {
			cout<<"No such book issued to you sir. Have a good day!"<<endl;
		}
	} else {
		cout<<"Book with ID doesnot exist."<<endl;
	}

	bst.erase(cnic);
	return 0;
}

void searchByTitle(){
	string search;
	cin.ignore();
	cout<<"Enter title: ";
	getline(cin, search);
	SIit it = title.find(search);
	if(it != title.end()){
		if(title.count(search) == 1){
			idit it2 = id.find(it->second);
			cout <<"\nBook id: "<<it->second<<"\n"<<"Title:" << it2->second.title<<" | Author: "<<it2->second.author<<" | Edition: "<<it2->second.edition << "\n\n";
		} else {
			it = title.begin();
			for (; it != title.end(); it++){
				if(it->first == search){
					idit it2 = id.find(it->second);
					cout <<"\nBook id: "<<it->second<<"\n"<<"Title:" << it2->second.title<<" | Author: "<<it2->second.author<<" | Edition: "<<it2->second.edition << "\n\n";
				}
			}
		}
    	cout << endl;
	} else {
		cout<<"\nWe're sorry. No book with given title is available!"<<endl;
	}
    cout << endl;
}

void searchByAuthor(){
	string search;
	cin.ignore();
	cout<<"Enter author: ";
	getline(cin, search);
	SIit it = author.find(search);
	if(it != author.end()){
		if(author.count(search) == 1){
			idit it2 = id.find(it->second);
			cout <<"\nBook id: "<<it->second<<"\n"<<"Title:" << it2->second.title<<" | Author: "<<it2->second.author<<" | Edition: "<<it2->second.edition << "\n\n";
		} else {
			it = author.begin();
			for (; it != author.end(); it++){
				if(it->first == search){
					idit it2 = id.find(it->second);
					cout <<"\nBook id: "<<it->second<<"\n"<<"Title:" << it2->second.title<<" | Author: "<<it2->second.author<<" | Edition: "<<it2->second.edition << "\n\n";
				}
			}
		}
    	cout << endl;
	} else {
		cout<<"\nWe're sorry. No book with given author is available!"<<endl;
	}
    cout << endl;
}