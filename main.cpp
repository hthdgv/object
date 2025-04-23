#include <iostream>
#include "Animal.h"
using namespace std;

int main() {
    string name, sound;
    int age;
    const int SIZE = 3;
    Animal* animals[SIZE];

    // ��J�ʪ����
    for (int i = 0; i < SIZE; i++) {
        cout << "�п�J�� " << i + 1 << " ���ʪ�����ơG" << endl;
        cout << "�W�r�G";
        getline(cin, name);
        cout << "�~�֡G";
        cin >> age;
        cin.ignore(); // ���������
        cout << "�s�n�G";
        getline(cin, sound);

        animals[i] = new Animal(name, age, sound);
        cout << endl;
    }

    // ��ܩҦ��ʪ�
    cout << "\n=== �Ҧ��ʪ������ ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        animals[i]->showInfo();
        cout << "-----------------" << endl;
    }

    // �έp�G�����~�֡B�̦~���P�̦~��
    int totalAge = 0;
    int maxAge = animals[0]->getAge();
    int minAge = animals[0]->getAge();
    string oldestName = animals[0]->getName();
    string youngestName = animals[0]->getName();

    for (int i = 0; i < SIZE; i++) {
        int currentAge = animals[i]->getAge();
        totalAge += currentAge;

        if (currentAge > maxAge) {
            maxAge = currentAge;
            oldestName = animals[i]->getName();
        }

        if (currentAge < minAge) {
            minAge = currentAge;
            youngestName = animals[i]->getName();
        }
    }

    double avgAge = (double)totalAge / SIZE;
    cout << "\n=== �~�ֲέp ===" << endl;
    cout << "�����~�֡G" << avgAge << endl;
    cout << "�̦~�����ʪ��G" << oldestName << "�]" << maxAge << " ���^" << endl;
    cout << "�̦~�����ʪ��G" << youngestName << "�]" << minAge << " ���^" << endl;

    // �M���O����
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    return 0;
}