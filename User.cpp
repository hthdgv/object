#include <iostream>
#include "User.h"

User::User(string n, string i) : name(n), id(i) {}
User::~User() {}

string User::getName() const { return name; }
string User::getID() const { return id; }

void User::borrowBook(const string& isbn) {
    borrowedBooks.push_back(isbn);
}

void User::returnBook(const string& isbn) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == isbn) {
            borrowedBooks.erase(it);
            break;
        }
    }
}

void User::showBorrowedBooks() const {
    if (borrowedBooks.empty()) {
        std::cout << "  No borrowed books." << std::endl;
    }
    else {
        std::cout << "  Borrowed books: ";
        for (const auto& b : borrowedBooks)
            std::cout << b << " ";
        std::cout << std::endl;
    }
}

