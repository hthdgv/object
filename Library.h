#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <map>
#include "Book.h"
#include "User.h"
using std::string;
using std::map;

class Library {
private:
    map<string, Book*> books;
    map<string, User*> users;

public:
    ~Library();

    void addBook(string title, string isbn);
    void addUser(string name, string id);
    void borrowBook(string userID, string isbn);
    void returnBook(string userID, string isbn);
    void showAllBooks() const;
    void showAllUsers() const;
    void queryBook(string isbn) const;
};

#endif


