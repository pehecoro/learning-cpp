#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

/**
 *  Simple example of references
 */

using namespace std;

void badTrade(string playerXItem, string playerYItem);
void goodTrade(string& playerXItem, string& playerYItem);
void showInventory(const vector<string>& inventory, const string& playerName);

int main(){

	const int MAX_SIZE = 3;

	const string playerXName = "Sonic";
	const string playerYName = "Mario";
	vector<string> inventoryPlayerX = {"Sword","Life Potion","Rat"};
	vector<string> inventoryPlayerY = {"Shield","Stick","Stone"};


	srand(static_cast<unsigned int>(time(0)));
	const int xItem = rand() % MAX_SIZE;
	const int yItem = rand() % MAX_SIZE;

	cout << "X Item to trade: " << inventoryPlayerX[xItem] << endl;
	cout << "Y Item to trade: " << inventoryPlayerY[yItem] << endl;
	cout << "   Before TRADES" << endl;

	showInventory(inventoryPlayerX, playerXName);
	showInventory(inventoryPlayerY, playerYName);

	badTrade(inventoryPlayerX[xItem],inventoryPlayerY[yItem]);

	cout << "   After BAD TRADE" << endl;

	showInventory(inventoryPlayerX, playerXName);
	showInventory(inventoryPlayerY, playerYName);

	goodTrade(inventoryPlayerX[xItem],inventoryPlayerY[yItem]);

	cout << "   After GOOD TRADE" << endl;

	showInventory(inventoryPlayerX, playerXName);
	showInventory(inventoryPlayerY, playerYName);

	return 0;
}

inline void badTrade(string playerItemX, string playerItemY){
	string aux = playerItemX;
	playerItemX = playerItemY;
	playerItemY = aux;
}

inline void goodTrade(string& playerItemX, string& playerItemY){
	string aux = playerItemX;
	playerItemX = playerItemY;
	playerItemY = aux;
}

void showInventory(const vector<string>& inventory, const string& playerName){
	cout << "===" << playerName << " Inventory ===" << endl;
	for(vector<string>::const_iterator i = inventory.begin(); i != inventory.end(); i++){
		cout << ">" << (*i) << endl;
	}
	cout  << "=====================" << endl;
}

