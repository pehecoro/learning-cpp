#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

/*
	Simple uses of Lambda
*/

struct Item {
	std::string name;
	float price;
	int amount;
};

struct Player {
	std::string name;
	float money;
};

void showProducts(std::vector<Item>& vendor) {
	std::cout << "+----Welcome to the store----+" << '\n';
	std::cout << "| Here's my products         |" << '\n';
	std::for_each(vendor.begin(), vendor.end(),
		[](Item i) {
		std::cout << i.name << "   " << i.price << "$      Amount: " << i.amount << '\n';
	}
	);
	std::cout << "|____________________________|" << '\n';
}

bool compareItem(Item a, Item b) {	return (a.name < b.name); }


int main() {

	const int MAX_MONEY = 30;

	srand(static_cast<unsigned int> (time(0)));

	Player p = { "Pedro", float(rand() % MAX_MONEY) };

	std::cout << "Welcome " << p.name << '\n';
	std::cout << "Money: " << p.money << "$" << '\n';


	std::vector<Item> vendor = { {"Apple",1.2f,3},
								{"Knife",7.3f,4},
								{ "Sword",15.1f,1},
								{ "Shield",12.5f,5 },
								{ "Staff",12.4f,7},
								};
	
	std::sort(vendor.begin(), vendor.end(), compareItem);

	showProducts(vendor);

	

	std::cout << "| Here's what you can buy    |" << '\n';
	std::for_each(vendor.begin(), vendor.end(),
		[=](Item i) {
			if (p.money >= i.price)std::cout << i.name << "   " << i.price << "$      Amount: " << i.amount << '\n';
		}
	);
	std::cout << "|____________________________|" << '\n';

	//Buy "randomly" what you can
	std::random_shuffle(vendor.begin(), vendor.end());

	std::cout << "+-----------Buying-----------+" << '\n';
	//Member variables are const, so if I want to change them I need to put 'mutable'
	//This case below I'm passing as references
	std::for_each(vendor.begin(), vendor.end(),
		[&](Item& i) {
			if (p.money >= i.price) {
				std::cout << "| " << p.name << ": Please, one " << i.name << '\n';
				p.money -= i.price;
				--i.amount;
			}
		}
	);
	std::cout << "|                            |" << '\n';
	std::cout << "| Money: " << p.money << "$" << '\n';
	std::cout << "|____________________________|" << '\n';

	std::sort(vendor.begin(), vendor.end(), compareItem);

	showProducts(vendor);

	std::cin.get();

	return 0;
}