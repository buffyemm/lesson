#include <iostream>
#include <string> // подключаем библиотеку для стринг
#include <vector>

struct product_ {

    std::string name;
    int price;
    int count;

};

std::vector<product_> shop;

int main()
{   
    shop.push_back({ "Cheese", 250, 0 });
    shop.push_back({ "Apple", 140, 10 });
    shop.push_back({ "Potato", 40, 24 });
    shop.push_back({ "Tomato", 260, 30 });
    shop.push_back({ "Chips", 160, 70 });
    shop.push_back({ "Bread", 40, 17 });
    shop.push_back({ "Macaroni", 140, 43 });

    int wallet = 2000; // кошелек пользлователя
    int number;
    int temp;
    while (wallet > 0) {

        
        std::cout << "\nYour Wallet: " << wallet << "\tAssortment: \n";
        std::cout << "Name\t\tPrice\tCount\n" << std::endl;

        for (int i = 0; i < shop.size(); i++) {

            std::cout << i + 1 << ". " << shop[i].name << "\t" << shop[i].price << "\t" << shop[i].count << std::endl;

        }

        std::cout << "Chouse number\n";

        std::cin >> number;

        if (shop[number - 1].count > 0) {

            std::cout << "Chouse count\n";
            std::cin >> temp;
            if (shop[number - 1].count >= temp) {
                if (shop[number - 1].price * temp < wallet) {

                    wallet -= temp * shop[number - 1].price; 

                    std::cout << "Buy: " << shop[number - 1].name << "\tTotal price: " << temp * shop[number - 1].price << std::endl;

                    shop[number - 1].count -= temp;

                    std::cout << "Wallet: " << wallet << std::endl;

                }
                else {

                    std::cout << "NO MONEY\t Total PRICE: " << shop[number - 1].price * temp << " > " << wallet;

                }
            }
            else {
            
                std::cout << "The quantity is less than the input\n";

            }

        }
        else {

            std::cout << "\nCount 0. It's over.\n";

        }
    }
}

