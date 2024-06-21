# Online Library Management System

## Problem Statement

### Part 1: Borrower Management

The Online Library Management System aims to manage borrowers, books, and book deliveries efficiently using various data structures and algorithms. Below are the detailed requirements and functionalities of the system:

#### Borrower Management

The system maintains information about borrowers using a Binary Search Tree (BST). Each borrower's information includes:

- **CNIC number**
- **Name**
- **Mobile number**
- **Address**

**Requirements:**
- Input borrower data from a file to construct the BST.
- Ensure the BST is balanced to achieve a height as close to log(n) as possible.

### Part 2: Book Delivery

Borrowers can request book deliveries to their addresses using a pre-defined map with around 30 node points. One node represents the library location.

**Requirements:**
- Utilize graph-based algorithms to find the shortest path from the library location (source) to the borrower's address (destination).
- Each group should use a different map configuration.

### Part 3: Book Management

The system manages data about books using a specialized data structure that ensures O(1) access time and handles collisions efficiently. Book information includes:

- **Title**
- **Author(s)**
- **Edition**
- **Publisher**
- **Issue Status**
- **Date of Issue**
- **Date of Return**
- **Borrower’s Id**

**Requirements:**
- Input book data from a file into the chosen data structure.
- Implement insert, update, and delete operations considering multiple copies and editions of books.
- Develop search functionalities by title, author, or both.
- Track book availability and implement issue and return operations accordingly.
- Implement a warning system for overdue books to notify borrowers.

### Additional Requirements

- **File Management**: Update files after insert, update, or delete operations to maintain data consistency.
- **Efficiency**: Ensure operations like search and data manipulation adhere to specified time complexities.
- **User Interface**: Develop a user-friendly interface for interaction with the system.

## Usage and Setup

### Setup Instructions

1. Clone the repository to your local machine.
2. Compile and run the main program file.
3. Follow on-screen instructions to interact with the system.
