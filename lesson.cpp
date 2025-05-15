#include <iostream>

void security() { // перенес в отдельную функцию

    int a;// переменная a, типа int, целые переменные

    std::cin >> a; // принимает ввод с консоли и кладет наш ввод в переменную а

    if (a < 18) { // если а меньше 18, мы выводим NO
        std::cout << "entrance denied\n";
    }
    else {
        std::cout << "you're welcome\n"; // если условие a < 18 не проходит выполняется иначе
    }

}

void elit_security() { // Мы пускаем людей с 18 лет до 30

    int a;// переменная a, типа int, целые переменные

    std::cin >> a; // принимает ввод с консоли и кладет наш ввод в переменную а

    if (a < 18) { // если а меньше 18, мы выводим NO

        std::cout << "entrance denied\n";

    }
    else if (a >= 30) {

        std::cout << "you're not welcome here\n";

    }
    else {
        
        std::cout << "you're welcome\n"; // если условие a < 18 не проходит и не проходит a >= 30, выполняется иначе
        
    }
}

int main()
{   
    security(); // запускаю функцию
    elit_security();// запускаю функцию

}

