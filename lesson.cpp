#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <vector>

using namespace std; // чтобы не писать названия пакета перед каждым вызовом


struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться


    string name;
    vector<int>portal;

};

location_ room[4];

int curren_loc = 0; // перменная следящая в какой локации игрок

void InitGame() {      // создаем функцию которая будет заносить все наши значения в массив room

    room[0].name = "Home";
    room[0].portal.push_back(1); 
    room[0].portal.push_back(2);

    room[1].name = "room";
    room[1].portal.push_back(0);
    room[2].name = "HUB";
    room[2].portal.push_back(0);

}


int main()
{   
    InitGame();
   
    int user_choice;

    while (true) {

        cout << room[curren_loc].name << endl; // выведем имя локации 0

        cout << "\tLocation number:\n";

        for (int i = 0; i < room[curren_loc].portal.size(); i++) {  // выведем порталы, цифры будут обозначать в какую локацию будут идти

            cout << room[curren_loc].portal[i] << endl;

        }

        cin >> user_choice;
        
        for (int i = 0; i < room[curren_loc].portal.size(); i++) {

            if (user_choice  == (room[curren_loc].portal[i])) {

                cout << "You're going location: " << room[user_choice].name << endl;
                curren_loc = user_choice;

            }

        }

    }
}

