#include <iostream>

int main()
{   

    int a;// переменная a, типа int, целые переменные

    std::cin >> a; // принимает ввод с консоли и кладет наш ввод в переменную а

    if (a < 18) { // если а меньше 18, мы выводим NO
        std::cout << "entrance denied\n";
    }
    else {
        std::cout << "you're welcome\n"; // если условие a < 18 не проходит выполняется иначе
    }

}

