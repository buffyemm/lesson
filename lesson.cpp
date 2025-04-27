#include <iostream>

void security() {

    int a;// переменная a, типа int, целые переменные

    std::cin >> a; // принимает ввод с консоли и кладет наш ввод в переменную а

    if (a < 18) { // если а меньше 18, мы выводим NO
        std::cout << "NO\n";
    }
    else {
        std::cout << "ok\n"; // если условие a < 18 не проходит выполняется иначе
    }

}

void elit_security() {

    int a;// переменная a, типа int, целые переменные

    std::cin >> a; // принимает ввод с консоли и кладет наш ввод в переменную а

    if (a < 18) { // если а меньше 18, мы выводим NO

        std::cout << "NO\n";

    }
    else if (a >= 30) {

        std::cout << "old\n";

    }
    else {
        
        std::cout << "ok\n"; // если условие a < 18 не проходит выполняется иначе
        
    }
}

int main()
{   
    security();
    elit_security();

 
}

