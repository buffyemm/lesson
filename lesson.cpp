#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class item_ {
    axe,
    sword,
    shield,  // Добавил shield
    key,
    hemlet
    
};

string itemLib[] = { "axe", "sword", "shield", "key", "hemlet"};

struct player_ {
    int hp;
    bool life = true;
    vector<item_> item;
    int current_loc = 0;
    bool attack = false;
};

struct enemy_ {  // Новая структура для врагов
    string name;
    int hp;
    int attack;
    bool alive;
    vector<item_> items;  // Инвентарь врага
    int current_loc;
};

struct portal_ {
    string name;
    int target;
    bool activ;
};

struct location_ {
    string name;
    vector<portal_> portal;
    vector<item_> item;
    vector<enemy_> enemy;  // Теперь enemy имеет тип enemy_

};

player_ user;
location_ room[4];

void InitGame() {
    room[0].name = "Home";
    room[0].portal.push_back({ "green_door", 1, true });
    room[0].portal.push_back({ "black_door", 2, false });
    room[0].item.push_back(item_::shield);


    room[1].name = "room";
    room[1].portal.push_back({ "back", 0, true });
    room[1].item.push_back(item_::sword);
    room[1].item.push_back(item_::hemlet);
    room[1].enemy.push_back({ "GOBLIN", 200, 10, true, {item_::sword, item_::shield}, 1 });  // Теперь работает!

    room[2].name = "Entrance";
    room[2].portal.push_back({ "back", 0, true });
    room[2].portal.push_back({ "iron_door", 3, false });

    room[3].name = "Street";

    user.hp = 200;
    user.item.push_back({ item_::key });
    user.item.push_back({ item_::sword });
}

void begin_fight() {

        for (int j = 0; j < room[user.current_loc].enemy.size(); j++) {

            if (user.current_loc == room[user.current_loc].enemy[j].current_loc) {

                cout << " You were attacked " << room[user.current_loc].enemy[j].name << endl;
                user.attack = true;
                /*for (int i = 0; i < room[user.current_loc].enemy[j].items.size(); i++) {
                    cout << "GOBLIN HAVE " << itemLib[(int)room[user.current_loc].enemy[j].items[i]] << endl;

                }*/
            }
            else {

                user.attack = false;

            }
        }
    
}



// use команда, будем реализовывать противника и вводить систему боевки похожую на камень ножницы бумага
int main()
{
    srand(time(NULL));

    InitGame();
    string chouse; // создали переменную для ввода пользователя

    cout << "You're in location: " << room[user.current_loc].name << endl; // выведем имя локации  в которой находится игрок

    while (user.life) { // цикл игры, пока пользователь живой

        begin_fight();

        cin >> chouse;


        if (chouse == "help") {

            cout << "1.go\n2.list\n3.trunk\n4.pick\n5.drop\n6.use\n";
        }


        if (chouse == "go") { // логика работы наших команд, если ввели go, нам будут показываться все доступные порталы в локации, где находится игрок

            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {  // идем по массиву порталов в кажой локции где находится персонаж

                auto p = room[user.current_loc].portal[i];

                cout << room[user.current_loc].portal[i].name << (p.activ ? " is unlocked" : " is locked") << endl; // здесь будут уже не цифры а имена порталов.
            }


            cin >> chouse;// повторный ввод на имя портала


            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {


                    if (chouse == room[user.current_loc].portal[i].name) { // если ввод пользователя сходится с именем портала локации

                        if (room[user.current_loc].portal[i].activ) { // проверка, на активен ли портал

                            user.current_loc = room[user.current_loc].portal[i].target; // то мы текущую локацию игрока, меняем на таргет портала, куда ведет портал, в какую комнату

                            cout << "You're in location: " << room[user.current_loc].name << endl;
                        }
                        else {
                            cout << "LOCKED\n";
                        }
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

        if (user.hp <= 0) {
            user.life = false;
        }

        if (chouse == "use") {

            int dir;

            

                if (!user.item.empty()) {

                    for (int i = 0; i < user.item.size(); i++) {

                        cout << i + 1 << ". " << itemLib[(int)user.item[i]] << endl;

                    }

                    cout << "Enter number item\n";

                    cin >> dir;
                    
                    
                        switch ((int)user.item[dir - 1]) {

                        case 0: {

                            cout << "use axe\n";

                            for (int i = 0; i < room[user.current_loc].enemy.size(); i++) {

                                if (room[user.current_loc].enemy[i].hp > 0 ) {

                                    int r = rand() % room[user.current_loc].enemy[i].items.size();

                                    if (room[user.current_loc].enemy[i].items[r] == item_::sword) {


                                        user.hp -= 40;
                                        room[user.current_loc].enemy[i].hp -= 50;
                                        cout << "You have attack " << room[user.current_loc].enemy[i].name << endl;
                                        cout << "You have damage\nYour hp: " << user.hp << endl;
                                        cout << "Goblin HP: " << room[user.current_loc].enemy[i].hp << endl;

                                    }
                                    else {

                                        cout << "Goblin DEFEND\n";

                                    }

                                }
                                else {

                                    cout << "You have killed " << room[user.current_loc].enemy[i].name << endl;
                                    room[user.current_loc].enemy.erase(room[user.current_loc].enemy.begin() + i);
                                    user.attack = false;
                                }
                            }

                            break;

                        }

                        case 1: {

                            cout << "use sword\n";

                            for (int i = 0; i < room[user.current_loc].enemy.size(); i++) {

                                if (room[user.current_loc].enemy[i].hp > 0) {

                                    int r = rand() % room[user.current_loc].enemy[i].items.size();

                                    if (room[user.current_loc].enemy[i].items[r] == item_::sword) {

                                        user.hp -= rand() % 100;
                                        room[user.current_loc].enemy[i].hp -= 40;
                                        cout << "You have attack " << room[user.current_loc].enemy[i].name << endl;
                                        cout << "You have damage\nYour hp: " << user.hp << endl;
                                        cout << "Goblin HP: " << room[user.current_loc].enemy[i].hp << endl;

                                    }
                                    else {

                                        cout << "Goblin DEFEND\n";

                                    }

                                }
                                else {

                                    cout << "You have killed " << room[user.current_loc].enemy[i].name << endl;
                                    room[user.current_loc].enemy.erase(room[user.current_loc].enemy.begin() + i);
                                    user.attack = false;
                                }
                            }

                            break;

                        }

                        case 2: {

                            cout << "use shield\n";

                            for (int i = 0; i < room[user.current_loc].enemy.size(); i++) {

                                if (user.attack) {

                                    int r = rand() % room[user.current_loc].enemy[i].items.size();

                                    if (room[user.current_loc].enemy[i].items[r] == item_::sword) {


                                        cout << "You have Defend" << endl;

                                    }
                                    else {

                                        cout << "Everyone raised their shields\n";

                                    }


                                }

                            }

                            break;

                        }

                        case 3: {

                            for (int i = 0; i < room[user.current_loc].portal.size(); i++) {

                                cout << i + 1 << ". " << room[user.current_loc].portal[i].name << endl;

                            }
                            cout << "Enter number door: \n";

                            cin >> dir;

                            room[user.current_loc].portal[dir - 1].activ ? room[user.current_loc].portal[dir - 1].activ = false : room[user.current_loc].portal[dir - 1].activ = true; //читайте про тернарный оператор

                            cout << "You're " << (room[user.current_loc].portal[dir - 1].activ ? "unlocked door " : "locked door ") << room[user.current_loc].portal[dir - 1].name << endl;

                            break;

                        }

                        case 4: {


                            user.hp += 100;
                            cout << "You are wearing a helmet\nYour HP has increased by 100\n";
                            break;

                        }

                        }

                   

                }
        }

    }
}





    


