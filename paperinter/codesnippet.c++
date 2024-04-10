#include<iostream>
using namespace std;
CODE SNIPPETS
// Class representing a Book
class Book {
public:
 string title;
 string author;
 string isbn;
 int publicationYear;
 bool available;
 Book(string t, string a, string i, int y) : title(t), author(a), isbn(i), publicationYear(y), available(true) {}
 void displayDetails() {
 cout << "Title: " << title << endl;
 cout << "Author: " << author << endl;
 cout << "ISBN: " << isbn << endl;
 cout << "Publication Year: " << publicationYear << endl;
 cout << "Available: " << (available ? "Yes" : "No") << endl;
 }
};
// Class representing a Librarian
class Librarian {
public:
 string name;
 Librarian(string n) : name(n) {}
 void addBook(vector<Book>& catalog, string title, string author, string isbn, int publicationYear) {
 catalog.push_back(Book(title, author, isbn, publicationYear));
 cout << "Book added to the catalog." << endl;
 }
 void displayCatalog(const vector<Book>& catalog) {
 cout << "Library Catalog:" << endl;
 for (const auto& book : catalog) {
 book.displayDetails();
 cout << endl;
 }
 }
 void issueBook(Book& book, Borrower& borrower) {
 if (book.available) {
 book.available = false;
 cout << "Book '" << book.title << "' issued to " << borrower.name << "." << endl;
 } else {
 cout << "Sorry, the book '" << book.title << "' is not available." << endl;
 }
 }
 void returnBook(Book& book) {
 book.available = true;
 cout << "Book '" << book.title << "' returned successfully." << endl;
 }
};
class User { public: string name; string userId;
User(string n, string id) : name(n),
userId(id) {}
void displayDetails() {
cout << "Name: " << name << endl; cout << "User ID: " << userId << endl; } };
int main()
{
    
}