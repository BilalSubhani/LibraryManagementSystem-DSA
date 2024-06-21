#define ADMINUSER "admin"
#define ADMINPASSWORD "admin123"

#define USER "user"   //student
#define USERPASSWORD "user123"

#define FINE 500

int addBook(); // title, author, edition, publisher, issue status, issue date, 
               //date of return, borrowers id

int deleteBook();

int updateBook();                   

int listOfAllBooks();

int borrowBook(); // cnic, name, mobile, address

int returnBook();

void searchByTitle();

void searchByAuthor();

// house no separate, then take input of block and area 