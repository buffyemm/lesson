#include <iostream>


int main()
{   
    srand(time(NULL));//помошник для функции рандома, который принимает в себя время компьютера
    int user;// переменная user, типа int, целые переменные
    int bot = 1 + rand() % 9; // в бот мы будем ставить функцию rand(), которая будет нам рандомить числа от 1 до 9

    std::cout << "Enter number 1 - 9\n";

    for (int i = 0; i < 10; i++) {


        std::cin >> user; // принимает ввод с консоли и кладет наш ввод в переменную user

        if (user == bot) { // условия победы

            std::cout << " you win\n";
            bot = 1 + rand() % 9;
        }
        else {

            std::cout << "you lose\n"; // если условия выше не выполняются, значит поражение
        }
    }
            std::cout << "Bot number: " << bot << std::endl;
}

