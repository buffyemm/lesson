#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <Windows.h>

int main()
{   
    SetConsoleCP(1251); // подключаем запись русского языка в string
    srand(time(NULL));//помошник для функции рандома, который принимает в себя время компьютера

    std::string user;// переменная user становиться string, уже можем вмещать некие слова

    int r = rand() % 3; // в r мы будем ставить функцию rand(), которая будет нам рандомить числа от 0 до 2, он будет выбирать позицию масива bot

    std::string bot[3]{ "rock", "scissors", "paper" };//создаем массив стринг,который будет считать двумерным массивом, и в него будем передавать r

    std::cout << "Введите число\n1.rock\n2.scissors\n3.paper\n";

    std::cin >> user; // принимает ввод с консоли и кладет наш ввод в переменную user

    if (user == "rock" && bot[r] == "scissors" || user == "scissors" && bot[r] == "paper" || user == "paper" && bot[r] == "rock") { // условия победы

        std::cout << "win\n";

    }
    else if (user == bot[r]) {// условия ничьи

        std::cout << "draw\n";

    }
    else {

        std::cout << "lose\n"; // если условия выше не выполняются, значит поражение

    }

    std::cout << r << std::endl;
}

