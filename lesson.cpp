#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <vector>

using namespace std;

struct player {

    int current_loc = 0; // переменная отвечает в какой локации будет находиться игрок
   
};


struct portal_ { // структура портала, в которой будут лежать все переменные, связанные с порталом

    string name; // имя портала
    int target;  // куда будет вести портал, в какую локацию

};

struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться

    string name; // имя локации
    vector<portal_>portal; // раньше вектор был типа int, но так как мы добавили структуру порталов, и имена порталов в структуре, нужно чтобы вектор был типа portal_ 

};

location_ room[4];


void InitGame() {       // создаем функцию которая будет заносить все наши значения в массив room

    room[0].name = "Home"; // задаем кажой комнате имя
    room[0].portal.push_back({"door", 1}); // закидываем в векотор portal с помощью метода: имя, и куда ведет локация
    room[1].name = "room";
    room[1].portal.push_back({"door_back", 0});

}


int main()
{   

    InitGame();
    
    cout << room[0].name << endl; // выведем имя локации 0

    for (int i = 0; i < room[0].portal.size(); i++) {  // идем по массиву порталов в кажой локции где находится персонаж

        cout << room[0].portal[i].name << endl; // здесь будут уже не цифры а имена порталов.

    }

}

