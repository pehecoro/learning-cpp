#include <iostream>
#include <string>
#include <vector>

/**
 * Simple Shop using Vectors
 */

using namespace std;

void showInventory();
void showShop();
void processCmd(int cmd);
void fillShop();
int sizeCPrice(int n);

typedef struct{
	string name;
	unsigned int price;
}item;


vector<string> inventory;
vector<item> shop;
unsigned int gold = 300;

int main(){

	cout << "      Welcome to Pehecoro Shop" << endl;
	cout << "To leave                       type 0" << endl;
	int cmd;
	fillShop();
	while(cmd != 0){
		processCmd(cmd);
		showInventory();
		showShop();
		cout << "Type the number of the item you want to buy" << endl;

		cout << ">";
		cin >> cmd;
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return 0;
}

void showInventory(){

	vector<string>::iterator it;
	cout << "==============INVENTORY==============" << endl;
	cout << "Item                         Gold:" << gold << endl << endl;
	for(it = inventory.begin(); it != inventory.end();  it++){
		cout << (*it) << endl;
	}
}

void showShop(){

	vector<item>::iterator it;
	int i = 1;
	cout << "================SHOP=================" << endl;
	for(it = shop.begin(); it != shop.end(); it++){
		string space(34-((it->name).size()+sizeCPrice(it->price)),' ');//Adjust space to show correctly =)
		cout << "[" << i << "]" << it->name << space << it->price << endl;
		i++;
	}

	cout << "=====================================" << endl;

}

void fillShop(){
	shop.push_back({"Mana Potion",50});
	shop.push_back({"Life Potion",25});
	shop.push_back({"Stick",10});
	shop.push_back({"Stone",5});
	shop.push_back({"Ruby",100});
}

void processCmd(int cmd){
	vector<item>::iterator it;
	int i = 1;
	for(it = shop.begin(); it != shop.end(); it++){
		if(cmd == i){
			if(gold >= it->price){
				inventory.push_back(it->name);
				gold -= it->price;
			}else{
				cout << "You don't have enough gold =(" << endl;
			}
		}
		i++;
	}
}

int sizeCPrice(int n){
	int i = 1;

	while(n >= 10){
		n /= 10;
		i++;
	}

	return i;
}

