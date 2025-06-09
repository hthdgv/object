#include "Book.h"

Book::Book(string t, string i) : title(t), isbn(i), isBorrowed(false), borrowerID("") {}

Book::~Book() {}

string Book::getTitle() const { return title; }
string Book::getISBN() const { return isbn; }
bool Book::getStatus() const { return isBorrowed; }
string Book::getBorrower() const { return borrowerID; }

void Book::borrow(const string& userID) {
    isBorrowed = true;
    borrowerID = userID;
}

void Book::returned() {
    isBorrowed = false;
    borrowerID.clear();
}

