#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
*	Smart Pointers
*/

using namespace std;

class Player {

	friend ostream& operator<<(ostream& os, const Player& player) {
		os << player.m_Name;
		return os;
	}
public:
	Player(const string &name) :m_Name(name) { cout << "Constructor " << name << endl; }
	~Player() { cout << "Destructor " << m_Name <<  endl; }

	void addItem(const string &item) {
		m_Inventory.push_back(item);
	}

	void showItems() {
		for (vector<string>::const_iterator it = m_Inventory.begin();
			it != m_Inventory.end(); it++) {
			cout << (*it) << endl;
		}
	}

private:
	string m_Name;
	vector<string> m_Inventory;

};


int main() {
	weak_ptr<Player> pWeakPlayer;
	{
		shared_ptr<Player> pSharedPlayer1;
		{
			unique_ptr<Player> pUniquePlayer = make_unique<Player>("Pedro Unique");
			cout << "pUniquePlayer name: " << (*pUniquePlayer) << endl;

			//Shared Pointer
			shared_ptr<Player> pSharedPlayer2 = make_shared<Player>("Pedro Shared");//Allocating memory
			pSharedPlayer1 = pSharedPlayer2;
		}
		//pSharedPlayer2 dies but delete only when the last shared pointer dies
		cout << "pSharedPlayer1 name: " << (*pSharedPlayer1) << endl;
		pWeakPlayer = pSharedPlayer1;
	}
	//The Weak pointer don't keep it alive, so use it only temporary.
	cout << "Weak pointer alive but ^" << endl;
	cin.get();

	return 0;
}
