#include <iostream>
#include "Library.h"

Library::~Library() {
    for (auto& pair : books) delete pair.second;
    for (auto& pair : users) delete pair.second;
}

void Library::addBook(string title, string isbn) {
    if (books.count(isbn)) {
        std::cout << "Book already exists: " << isbn << std::endl;
        return;
    }
    books[isbn] = new Book(title, isbn);
    std::cout << "Book added: " << title << std::endl;
}

void Library::addUser(string name, string id) {
    if (users.count(id)) {
        std::cout << "User already exists: " << id << std::endl;
        return;
    }
    users[id] = new User(name, id);
    std::cout << "User added: " << name << std::endl;
}

void Library::borrowBook(string userID, string isbn) {
    if (!books.count(isbn) || !users.count(userID)) {
        std::cout << "Invalid book or user." << std::endl;
        return;
    }
    Book* book = books[isbn];
    if (book->getStatus()) {
        std::cout << "Book already borrowed by: " << book->getBorrower() << std::endl;
        return;
    }
    book->borrow(userID);
    users[userID]->borrowBook(isbn);
    std::cout << "Book borrowed: " << book->getTitle() << std::endl;
}

void Library::returnBook(string userID, string isbn) {
    if (!books.count(isbn) || !users.count(userID)) {
        std::cout << "Invalid book or user." << std::endl;
        return;
    }
    Book* book = books[isbn];
    if (!book->getStatus() || book->getBorrower() != userID) {
        std::cout << "Book is not borrowed by this user." << std::endl;
        return;
    }
    book->returned();
    users[userID]->returnBook(isbn);
    std::cout << "Book returned: " << book->getTitle() << std::endl;
}

void Library::showAllBooks() const {
    std::cout << "\nBooks in library:" << std::endl;
    for (const auto& pair : books) {
        const Book* b = pair.second;
        std::cout << "ISBN: " << b->getISBN()
            << " | Title: " << b->getTitle()
            << " | Status: " << (b->getStatus() ? "Borrowed" : "Available") << std::endl;
    }
}

void Library::showAllUsers() const {
    std::cout << "\nUsers in system:" << std::endl;
    for (const auto& pair : users) {
        const User* u = pair.second;
        std::cout << "ID: " << u->getID() << " | Name: " << u->getName() << std::endl;
        u->showBorrowedBooks();
    }
}

void Library::queryBook(string isbn) const {
    if (!books.count(isbn)) {
        std::cout << "Book not found." << std::endl;
        return;
    }
    const Book* b = books.at(isbn);
    std::cout << "Title: " << b->getTitle()
        << " | Status: " << (b->getStatus() ? ("Borrowed by " + b->getBorrower()) : "Available") << std::endl;
}

