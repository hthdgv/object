#include <iostream>
#include "Animal.h"
using namespace std;

int main() {
    string name, sound;
    int age;
    const int SIZE = 3;
    Animal* animals[SIZE];

    // 輸入動物資料
    for (int i = 0; i < SIZE; i++) {
        cout << "請輸入第 " << i + 1 << " 隻動物的資料：" << endl;
        cout << "名字：";
        getline(cin, name);
        cout << "年齡：";
        cin >> age;
        cin.ignore(); // 忽略換行符
        cout << "叫聲：";
        getline(cin, sound);

        animals[i] = new Animal(name, age, sound);
        cout << endl;
    }

    // 顯示所有動物
    cout << "\n=== 所有動物的資料 ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        animals[i]->showInfo();
        cout << "-----------------" << endl;
    }

    // 統計：平均年齡、最年輕與最年長
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
    cout << "\n=== 年齡統計 ===" << endl;
    cout << "平均年齡：" << avgAge << endl;
    cout << "最年長的動物：" << oldestName << "（" << maxAge << " 歲）" << endl;
    cout << "最年輕的動物：" << youngestName << "（" << minAge << " 歲）" << endl;

    // 清除記憶體
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    return 0;
}