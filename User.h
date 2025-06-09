#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class User {
private:
    string name;
    string id;
    vector<string> borrowedBooks;

public:
    User(string name, string id);
    ~User();

    string getName() const;
    string getID() const;

    void borrowBook(const string& isbn);
    void returnBook(const string& isbn);
    void showBorrowedBooks() const;
};

#endif


