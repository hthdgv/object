
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;
    string sound;

public:
    Animal(string n, int a, string s); // �غc�l�a�T�ӰѼ�
    void showInfo();
    string getName();
    int getAge();
};

#endif