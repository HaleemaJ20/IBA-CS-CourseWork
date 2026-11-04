#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    int pages;
    bool isAvailable;

public:
    Book(string t, string a, string i, int p)
        : title(t), author(a), isbn(i), pages(p), isAvailable(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    int getPages() const { return pages; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully." << endl;
    }

    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Pages: " << pages << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    bool operator<(const Book& other) const {
        return pages < other.pages;
    }

    bool operator>(const Book& other) const {
        return pages > other.pages;
    }

    bool operator==(const Book& other) const {
        return isbn == other.isbn;
    }

    Book operator+(const Book& other) const {
        return Book(title, author, isbn, pages + other.pages);
    }
};

int main() {
    Book b1("C++ Programming", "Bjarne Stroustrup",
            "978-0321563840", 1376);
    Book b2("The C++ Language", "Bjarne Stroustrup",
            "978-0201889543", 1040);
    Book b3("Effective C++", "Scott Meyers",
            "978-0321334879", 320);

    cout << "--- Book Information ---" << endl;
    b1.displayInfo();
    b2.displayInfo();
    b3.displayInfo();

    b1.borrowBook();
    cout << "\nAfter borrowing b1:" << endl;
    cout << "Is b1 available? " << (b1.getAvailability() ? "Yes" : "No") << endl;

    b1.returnBook();

    if (b3 < b1) {
        cout << "\n" << b3.getTitle() << " has fewer pages than "
             << b1.getTitle() << endl;
    }

    if (b1 > b2) {
        cout << b1.getTitle() << " has more pages than "
             << b2.getTitle() << endl;
    }

    Book b4("C++ Programming", "Author", "978-0321563840", 500);
    if (b1 == b4) {
        cout << "\nb1 and b4 have the same ISBN" << endl;
    }

    Book anthology = b1 + b2;
    cout << "\nCombined anthology:" << endl;
    anthology.displayInfo();

    return 0;
}
