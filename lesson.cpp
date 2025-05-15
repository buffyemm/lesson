#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <vector>

using namespace std; // чтобы не писать названия пакета перед каждым вызовом


struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться


    string name;
    vector<int>portal;

};

location_ room[4];


void InitGame() {       // создаем функцию которая будет заносить все наши значения в массив room

    room[0].name = "Home";
    room[0].portal.push_back(1); 
    room[1].name = "room";
    room[1].portal.push_back(0);

}


int main()
{   
    InitGame();
    
    cout << room[0].name << endl; // выведем имя локации 0

    for (int i = 0; i < room[0].portal.size(); i++) {  // выведем порталы, цифры будут обозначать в какую локацию будут идти

        cout << room[0].portal[i] << endl;


    }

}

