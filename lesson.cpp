#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <Windows.h>
#include <vector>

using namespace std;

enum class item_ { // структура предметов, в ней представленны значения в виде чисел, axe содержит в себе 0, sword содержит 1 и т.д

    axe,
    sword,
    hemlet,
    key
    
};

string itemLib[] = {"axe", "sword", "hemlet", "key"};// создали массив в который будет передаваться содержимое вектора инвентаря 


struct player_ {

    int current_loc = 0; // переменная отвечает в какой локации будет находиться игрок
    bool life = true; // переменная, отвечающая за жизнь игрока
    vector<item_> item_p; // созадим вектор типа item_, это будет наш инвенарь, там будут храниться наши предметы в виде цифр.
};


struct portal_ { // структура портала, в которой будут лежать все переменные, связанные с порталом

    string name; // имя портала
    int target;  // куда будет вести портал, в какую локацию
    bool activ;
};

struct location_ {      // создали структуру локации, в ней есть имя и наши портал, по которым мы будем перемещаться

    
    string name; // имя локации
    vector<portal_>portal; // раньше вектор был типа int, но так как мы добавили структуру порталов, и имена порталов в структуре, нужно чтобы вектор был типа portal_ 
    vector<item_>item_l;
};

player_ user; // создали глобальную переменную игрока
location_ room[4];


void InitGame() {       // создаем функцию которая будет заносить все наши значения в массив room
    
    
    room[0].name = "Дом"; // задаем кажой комнате имя
    room[0].portal.push_back({"door", 1, false}); // закидываем в векотор portal с помощью метода: имя, и куда ведет локация
    room[0].item_l.push_back(item_::key);
    room[0].portal.push_back({ "door2", 2, false });

    room[1].name = "Комната";
    room[1].portal.push_back({"back", 0, true});
    room[1].item_l.push_back(item_::hemlet);

    room[2].name = "Подъезд";
    room[2].portal.push_back({ "back", 0, true });
    room[2].portal.push_back({ "iron_door", 3, false });
    room[2].item_l.push_back(item_::axe);
    room[2].item_l.push_back(item_::sword);

    room[3].name = "Улица";
    room[3].portal.push_back({ "back", 2, true });
    room[3].item_l.push_back(item_::sword);


}

// реализуем скрытые порталы  и команду open

int main()
{   
    SetConsoleCP(1251); // подключаем запись русского языка в string
    setlocale(LC_ALL, "Ru");// подключаем русский язык для вывода в консоль

    InitGame();
    string ch; // создали переменную для ввода пользователя

    cout << "You in location: " << room[user.current_loc].name << endl; // выведем имя локации  в которой находится игрок

    while (user.life) { // цикл игры, пока пользователь живой


        cin >> ch;

        if (ch == "go") { // логика работы наших команд, если ввели go, нам будут показываться все доступные порталы в локации, где находится игрок

            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {  // идем по массиву порталов в кажой локции где находится персонаж

                auto p = room[user.current_loc].portal[i];
                cout << room[user.current_loc].portal[i].name << (p.activ? " unlocked\n" : " locked\n");
                //cout << endl; //  имена порталов.

            }

            cout << "Enter name portal  \n";

            cin >> ch;// повторный ввод на имя портала

            //if (ch != "no") {

                for (int i = 0; i < room[user.current_loc].portal.size(); i++) {

                    if (ch == room[user.current_loc].portal[i].name) { // если ввод пользователя сходится с именем портала локации

                        if (room[user.current_loc].portal[i].activ) {


                            user.current_loc = room[user.current_loc].portal[i].target; // то мы текущую локацию игрока, меняем на таргет портала, куда ведет портал, в какую комнату

                            cout << "You have moved in: " << room[user.current_loc].name << endl;
                        }
                        else {

                            cout << "DOOR LOCKED\n";
                        }
                    }
                    /*else {
                        cout << "ERROR\n";
                    }*/

                }

            //}

        }


        if (ch == "item") {
            if (!user.item_p.empty()) { // проверка на не пуст ли инвентарь

                for (int i = 0; i < user.item_p.size(); i++) { // идем по массиву ite_p, нам нужна его размерность 

                    // будут выводиться только цифры
                    cout << "Your item: " << itemLib[(int)user.item_p[i]] << endl; // закидываем наш вектор предметов игрока и нам уже выводиться текст

                }
            }
            else {

                cout << "Your inventory is empty\n";

            }
        }

        if (ch == "q") {

            break; // выход из цикла
        }

        if (ch == "help") {

            cout << "Command:\n1.go\n2.item\n3.q\n4.search\n5.pick\n6.use\n";


        }


        if (ch == "search") { //Команда поиска, в нее встроил сразу подбор предмета

            if (!room[user.current_loc].item_l.empty()) { // проверка на не пуста ли локация

                for (int i = 0; i < room[user.current_loc].item_l.size(); i++) { // идем по массиву предметов текущей локации

                    cout << "You find item: " << itemLib[(int)room[user.current_loc].item_l[i]] << endl;

                }
            }
            else {

                cout << "Предметов нет.\n";
            }
        }


        if (ch == "pick") {

            cin >> ch;

                for (int i = 0; i < room[user.current_loc].item_l.size(); i++) {

                    if (ch == itemLib[(int)room[user.current_loc].item_l[i]]) {// проверка совпал ли ввод пользователя с названием предмета

                        user.item_p.push_back(room[user.current_loc].item_l[i]); // кладем предмет из локаии который мы ввели в предметы игрока

                        cout << "Вы подобрали предмет: " << itemLib[(int)room[user.current_loc].item_l[i]] << endl;

                        room[user.current_loc].item_l.erase(room[user.current_loc].item_l.cbegin() + i); //удаляем из локации этот предмет

                    }

                }
        }


        if (ch == "use") {

            cout << "Enter item\n";

            string a;
            cin >> a;

            if (!user.item_p.empty()) {

                for (int i = 0; i < user.item_p.size(); i++) {

                    if (itemLib[(int)user.item_p[i]] == a) {

                        switch ((int)user.item_p[i])
                        {
                               case 0: {
                               
                                   if (room[user.current_loc].name == "Home") {

                                       cout << "Вы зарубили бабку топором\n";
                                       break;
                                   }

                               }
                               
                               case 1: {

                                   if (user.current_loc == 2) {

                                       cout << "Вы закололи бабку\n";
                                       break;
                                   }

                               }

                               case 2: {

                                   if (user.current_loc == 2) {

                                       cout << "Вы испугали бабку\n";
                                       break;
                                   }

                               }
                               
                               case 3: {

                                   if (user.current_loc == 0) {

                                       room[0].portal[1].activ = true;
                                       cout << "You open door\n";
                                   }
                                   else if (user.current_loc == 2) {
                                       room[2].portal[1].activ = true;
                                       cout << "You open iron door\n";

                                   }
                                       break;

                               }
                                //
                               default: {

                                   cout << "не тот предмет";
                                   break;
                               }

                        }





                        /*room[0].portal[0].activ = true;
                        cout << "Дверь открыта\n";*/

                    }
                    else {

                        cout << "У вас нет предмета\n";

                    }


                }


        }


    }
}

