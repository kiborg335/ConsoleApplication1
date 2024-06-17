#include <iostream>
#include <locale>
#include <cstdlib>
#include <Windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string answer;
    system("start ConsoleApplication2.exe");

    while (true) {

        cout << "Купи слона!" << endl;
        getline(cin, answer);
        cout << "Всі кажуть " << answer << ", а ти купи слона!" << endl;
    }
    return 0;
}