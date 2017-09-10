#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/**
 * Simple use of Pointers
 */

using namespace std;


void showInventory(const vector<string>* const inventory);
void askTrade(string item,vector<string>* const inventory);

int main(){

	vector<string> inventory = {"Knife","Blank Card","Stone"};
	vector<string> offer = {"Sword","Ruby","Apple"};

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(offer.begin(),offer.end());

	showInventory(&inventory);

	askTrade(offer[0],&inventory);

	showInventory(&inventory);

	return 0;
}

void showInventory(const vector<string>* const inventory){
	cout << "=======Inventory========" << endl;
	for(unsigned int i = 0; i < inventory->size(); i++){
		cout << "Slot[" << i << "]: " << inventory->at(i) << endl;
	}
}

void askTrade(string item,vector<string>* const inventory){
	char answer;
	int randomItem = rand() % inventory->size();
	cout << "Do you want to swap your  " << inventory->at(randomItem) <<
			" for a "<< item <<"? (y/n)" << endl;
	cin >> answer;
	answer = toupper(answer);
	if(answer == 'Y'){
		inventory->at(randomItem) = item;
		cout << "Great deal.. or not" << endl;
	}else{
		cout << "Ok.." << endl;
	}
}
