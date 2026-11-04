#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    string itemID;
    bool isAvailable;

public:
    LibraryItem(string t, string id)
        : title(t), itemID(id), isAvailable(true) {
        cout << "LibraryItem constructor called\n";
    }

    virtual void displayDetails() const = 0;      // pure virtual
    virtual int calculateLoanDuration() const = 0; // pure virtual

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " checked out successfully.\n";
        } else {
            cout << title << " is already issued.\n";
        }
    }

    void returnItem() {
        isAvailable = true;
        cout << title << " returned.\n";
    }

    bool getAvailability() const {
        return isAvailable;
    }

    virtual ~LibraryItem() {
        cout << "LibraryItem destructor called\n";
    }
};

//DERIVED CLASS: BOOK 

class Book : public LibraryItem {
private:
    string author;
    int pageCount;

public:
    Book(string t, string id, string a, int pages)
        : LibraryItem(t, id), author(a), pageCount(pages) {
        cout << "Book constructor called\n";
    }

    void displayDetails() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pageCount << endl;
        cout << "Loan Duration: " << calculateLoanDuration() << " days\n";
    }

    int calculateLoanDuration() const override {
        return 14; // 2 weeks
    }
};

//DERIVED CLASS: DVD 

class DVD : public LibraryItem {
private:
    string director;
    int durationMinutes;

public:
    DVD(string t, string id, string d, int duration)
        : LibraryItem(t, id), director(d), durationMinutes(duration) {
        cout << "DVD constructor called\n";
    }

    void displayDetails() const override {
        cout << "DVD Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << durationMinutes << " minutes\n";
        cout << "Loan Duration: " << calculateLoanDuration() << " days\n";
    }

    int calculateLoanDuration() const override {
        return 7; // 1 week
    }
};

//DERIVED CLASS: MAGAZINE 

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string id, int issue)
        : LibraryItem(t, id), issueNumber(issue) {
        cout << "Magazine constructor called\n";
    }

    void displayDetails() const override {
        cout << "Magazine Title: " << title << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Loan Duration: " << calculateLoanDuration() << " days\n";
    }

    int calculateLoanDuration() const override {
        return 3; 
    }
};


int main() {

    LibraryItem* items[3];

    items[0] = new Book("C++ Programming", "B101", "Bjarne", 500);
    items[1] = new DVD("Inception", "D202", "Nolan", 148);
    items[2] = new Magazine("Tech Today", "M303", 45);

    cout << "\n--- Displaying Items ---\n";
    for (int i = 0; i < 3; i++) {
        items[i]->displayDetails();
        cout << endl;
    }

    cout << "\n--- Checkout Process ---\n";
    items[0]->checkOut();
    items[0]->checkOut(); // already issued
    items[0]->returnItem();

    cout << "\n--- Loan Durations (Polymorphism) ---\n";
    for (int i = 0; i < 3; i++) {
        cout << items[i]->calculateLoanDuration() << " days\n";
    }

    for (int i = 0; i < 3; i++) {
        delete items[i];
    }

    return 0;
}
