
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
    Animal(string n, int a, string s); // 建構子帶三個參數
    void showInfo();
    string getName();
    int getAge();
};

#endif