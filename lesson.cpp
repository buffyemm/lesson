#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <vector>

using namespace std;

enum class item_ { // структура предметов, в ней представленны значения в виде чисел, axe содержит в себе 0, sword содержит 1 и т.д

    axe,
    sword,
    hemlet,
    key
};

string itemLib[] = { "axe","sword","hemlet", "key" }; // создал массив с именами предметов, в который будут передаваться предметы 

struct player_ {

    int current_loc = 0; // переменная отвечает в какой локации будет находиться игрок
    bool life = true; // переменная, отвечающая за жизнь игрока
    vector<item_> item; // созадим вектор типа item_, это будет наш инвенарь, там будут храниться наши предметы в виде цифр.
};


struct portal_ { // структура портала, в которой будут лежать все переменные, связанные с порталом

    string name; // имя портала
    int target;  // куда будет вести портал, в какую локацию

};

struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться

    string name; // имя локации
    vector<portal_>portal; // раньше вектор был типа int, но так как мы добавили структуру порталов, и имена порталов в структуре, нужно чтобы вектор был типа portal_ 
    vector<item_>item;

};

player_ user; // создали глобальную переменную игрока
location_ room[4];

void InitGame() {       // создаем функцию которая будет заносить все наши значения в массив room

    room[0].name = "Home"; // задаем кажой комнате имя
    room[0].portal.push_back({ "door", 1 }); // закидываем в векотор portal с помощью метода: имя, и куда ведет локация
    room[0].portal.push_back({ "door2", 2 });
    room[0].item.push_back((item_::axe));// закинул предмет

    room[1].name = "room";
    room[1].portal.push_back({ "back", 0 });
    room[1].item.push_back((item_::sword));// закинули предмет
    room[1].item.push_back((item_::hemlet));

    room[2].name = "Entrance";
    room[2].portal.push_back({ "back", 0 });
    room[2].portal.push_back({ "iron_door", 3 });

    room[3].name = "Street";

    user.item.push_back(item_::key); // добавили в наш инвентарь топор, чтобы протестировать

}

// создадим команду Drop
int main()
{

    InitGame();
    string chouse; // создали переменную для ввода пользователя

    cout << "You're in location: " << room[user.current_loc].name << endl; // выведем имя локации  в которой находится игрок

    while (user.life) { // цикл игры, пока пользователь живой

        cin >> chouse;

        if (chouse == "help") {

            cout << "1.go\n2.list\n3.trunk\n4.pick\n5.drop\n";
        }


        if (chouse == "go") { // логика работы наших команд, если ввели go, нам будут показываться все доступные порталы в локации, где находится игрок

            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {  // идем по массиву порталов в кажой локции где находится персонаж

                cout << room[user.current_loc].portal[i].name << endl; // здесь будут уже не цифры а имена порталов.
            }


            cin >> chouse;// повторный ввод на имя портала


            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {

                if (chouse == room[user.current_loc].portal[i].name) { // если ввод пользователя сходится с именем портала локации

                    user.current_loc = room[user.current_loc].portal[i].target; // то мы текущую локацию игрока, меняем на таргет портала, куда ведет портал, в какую комнату

                    cout << "You're in location: " << room[user.current_loc].name << endl;

                }
            }
        }

        if (chouse == "trunk") {

            for (int i = 0; i < user.item.size(); i++) { // идем по массиву item, нам нужна его размерность 
                cout << itemLib[(int)user.item[i]] << endl; // я прировнял цифровые переменные, которые храняться в массиве инвентаря к int и передаю в массив string

            }

        }

        if (chouse == "list") { //  показать все предметы, находящиеся в локации

            cout << "You have found: \n";

            for (int i = 0; i < room[user.current_loc].item.size(); i++) {

                cout << itemLib[(int)room[user.current_loc].item[i]] << endl;
            }

        }

        if (chouse == "pick") { // подобрать предмет

            cin >> chouse;

            for (int i = 0; i < room[user.current_loc].item.size(); i++) {

                if (chouse == itemLib[(int)room[user.current_loc].item[i]]) {

                    cout << "You have picked item: " << itemLib[(int)room[user.current_loc].item[i]] << endl;
                    user.item.emplace_back(room[user.current_loc].item[i]); // добавил предмет в инвентарь игрока
                    room[user.current_loc].item.erase(room[user.current_loc].item.cbegin() + i); // удалил предмет из локации

                }

            }

        }

        if (chouse == "drop") {

            cin >> chouse;

            for (int i = 0; i < user.item.size(); i++) {

                if (chouse == itemLib[(int)user.item[i]]) {

                    cout << "You have deleted item: " << itemLib[(int)user.item[i]] << endl;
                    room[user.current_loc].item.emplace_back(user.item[i]); // добавил предмет в инвентарь локации
                    user.item.erase(user.item.cbegin() + i); // удалил предмет из инвенторя игрока

                }

            }


        }


    }
}

