#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

void showMenu() {
    cout << "\n--- �Ϯ��]�t�� ---\n";
    cout << "1. �s�W���y\n";
    cout << "2. �s�W�ϥΪ�\n";
    cout << "3. �ɮ�\n";
    cout << "4. �ٮ�\n";
    cout << "5. ��ܩҦ����y\n";
    cout << "6. ��ܩҦ��ϥΪ�\n";
    cout << "7. �d�߮��y���A\n";
    cout << "0. ���}�t��\n";
    cout << "�п�ܡG";
}

int main() {
    Library lib;
    int choice;
    string title, isbn, name, id;
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore(); // ���������

        switch (choice) {
        case 1:
            cout << "�ѦW�G";
            getline(cin, title);
            cout << "ISBN�G";
            getline(cin, isbn);
            lib.addBook(title, isbn);
            break;
        case 2:
            cout << "�ϥΪ̩m�W�G";
            getline(cin, name);
            cout << "�ϥΪ�ID�G";
            getline(cin, id);
            lib.addUser(name, id);
            break;
        case 3:
            cout << "�ϥΪ�ID�G";
            getline(cin, id);
            cout << "���yISBN�G";
            getline(cin, isbn);
            lib.borrowBook(id, isbn);
            break;
        case 4:
            cout << "�ϥΪ�ID�G";
            getline(cin, id);
            cout << "���yISBN�G";
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
            cout << "��J���yISBN�G";
            getline(cin, isbn);
            lib.queryBook(isbn);
            break;
        case 0:
            cout << "�A���I" << endl;
            return 0;
        default:
            cout << "�L�Ŀﶵ�A�Э��s��J�C" << endl;
        }
    }
}

