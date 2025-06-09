#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

void showMenu() {
    cout << "\n--- 圖書館系統 ---\n";
    cout << "1. 新增書籍\n";
    cout << "2. 新增使用者\n";
    cout << "3. 借書\n";
    cout << "4. 還書\n";
    cout << "5. 顯示所有書籍\n";
    cout << "6. 顯示所有使用者\n";
    cout << "7. 查詢書籍狀態\n";
    cout << "0. 離開系統\n";
    cout << "請選擇：";
}

int main() {
    Library lib;
    int choice;
    string title, isbn, name, id;
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore(); // 忽略換行符

        switch (choice) {
        case 1:
            cout << "書名：";
            getline(cin, title);
            cout << "ISBN：";
            getline(cin, isbn);
            lib.addBook(title, isbn);
            break;
        case 2:
            cout << "使用者姓名：";
            getline(cin, name);
            cout << "使用者ID：";
            getline(cin, id);
            lib.addUser(name, id);
            break;
        case 3:
            cout << "使用者ID：";
            getline(cin, id);
            cout << "書籍ISBN：";
            getline(cin, isbn);
            lib.borrowBook(id, isbn);
            break;
        case 4:
            cout << "使用者ID：";
            getline(cin, id);
            cout << "書籍ISBN：";
            getline(cin, isbn);
            lib.returnBook(id, isbn);
            break;
        case 5:
            lib.showAllBooks();
            break;
        case 6:
            lib.showAllUsers();
            break;
        case 7:
            cout << "輸入書籍ISBN：";
            getline(cin, isbn);
            lib.queryBook(isbn);
            break;
        case 0:
            cout << "再見！" << endl;
            return 0;
        default:
            cout << "無效選項，請重新輸入。" << endl;
        }
    }
}

