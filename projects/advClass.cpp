#include <iostream>
#include <string>
#include <vector>

/**
 * Training Friend Functions, overloading operators(cooool)
 * and container data members
 */

using namespace std;

class Item{

		friend Item operator+(Item t1, Item t2);
		friend ostream& operator<<(ostream& os, const Item& item);
	public:
		Item(const string& name, float price, unsigned int units);
		string getName() const;
	private:
		string m_Name;
		float m_Price;
		unsigned int m_Units;
};

Item::Item(const string& name, float price, unsigned int units):
	m_Name(name),
	m_Price(price),
	m_Units(units){}

inline string Item::getName() const{
	return m_Name;
}

class Treasure{

		friend ostream& operator<<(ostream& os, const Treasure& treasure);
	public:
		Treasure(const string& description, int space = 1);
		void addItem(const Item& item);
	private:
		string m_Description;
		vector<Item> m_Items;
		int m_Space;

};

//Overloading the operator, soooo cooolll omg
ostream& operator<<(ostream& os, const Treasure& treasure){
	cout << "The " << treasure.m_Description << " has " << endl;
	for(vector<Item>::const_iterator it = treasure.m_Items.begin();
			it != treasure.m_Items.end(); it++){
		cout << it->getName() << endl;
	}
	return os;
}

Item operator+(Item t1, Item t2){
	if(t1.m_Name == t2.m_Name){
		t1.m_Units += t2.m_Units;
	}else{
		cout << "There's no possible way to sum this =(" << endl;
	}

	return t1;
}

ostream& operator<<(ostream& os, const Item& item){
	cout << "===" << item.m_Name << "===" << endl;
	cout << "Price: " << item.m_Price << endl;
	cout << "Units: " << item.m_Units << endl;
	cout << string((6+item.m_Name.size()),'=') << endl;
	return os;
}

Treasure::Treasure(const string& description, int space):
		m_Description(description),
		m_Space(space){
	m_Items.reserve(space);
}

void Treasure::addItem(const Item& item){
	m_Items.push_back(item);
}

int main(){

	Treasure treasure("Gold treasure",3);

	cout << treasure << endl;

	treasure.addItem(Item("Stone",0.1,2));
	treasure.addItem(Item("Dragon Scale",10.3,1));
	treasure.addItem(Item("Stick",0.4,5));

	cout << treasure << endl;

	Item item1("Flower",0.2,2);
	Item item2("Flower",0.2,4);

	Item item3 = item1 + item2;
	cout << item3 << endl;

	return 0;
}
