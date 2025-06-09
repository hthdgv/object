#ifndef BOOK_H
#define BOOK_H

#include <string>
using std::string;

class Book {
private:
    string title;
    string isbn;
    bool isBorrowed;
    string borrowerID;

public:
    Book(string title, string isbn);
    ~Book();

    string getTitle() const;
    string getISBN() const;
    bool getStatus() const;
    string getBorrower() const;

    void borrow(const string& userID);
    void returned();
};

#endif


