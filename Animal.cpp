// Animal.cpp
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(string n, int a, string s) {
    name = n;
    age = a;
    sound = s;
}

void Animal::showInfo() {
    cout << "¦W¦r¡G" << name << endl;
    cout << "¦~ÄÖ¡G" << age << endl;
    cout << "¥sÁn¡G" << sound << endl;
}
string Animal::getName() {
    return name;
}
int Animal::getAge() {
    return age;
}