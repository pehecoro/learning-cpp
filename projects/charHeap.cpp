#include <iostream>
#include <string>

/**
 * Dynamic Memory
 */

using namespace std;

class Character{

		friend ostream& operator<<(ostream& os, const Character& c);
	public:
		Character(const string& name, const string& race, int level = 1);
		Character(const Character& character);
		~Character();//Destructor
		Character& operator=(const Character& character);
	private:
		string* m_pName;
		string* m_pRace;
		int m_Level;

};

ostream& operator<<(ostream& os, const Character& c){
	cout << "Character " << *(c.m_pName) << endl;
	cout << "Race: " << *(c.m_pRace) << endl;
	cout << "Level: " << c.m_Level << endl;

	return os;
}

Character::Character(const string& name, const string& race, int level):
	m_pName(new string(name)),m_pRace(new string(race)),//Allocating memory on the heap
	m_Level(level){}

//Copy constructor
Character::Character(const Character& character){
	cout << "Copy constructor called" << endl;
	m_pName = new string(*character.m_pName);
	m_pRace = new string(*character.m_pRace);
	m_Level = character.m_Level;
}

Character::~Character(){
	delete m_pName;
	delete m_pRace;
}

Character& Character::operator=(const Character& character){
	cout << "Operator = called" << endl;
	if(this != &character){
		cout << "Character different, soo..." << endl;
		delete m_pName;//free memory
		m_pName = new string(*(character.m_pName));
		delete m_pRace;
		m_pRace = new string(*(character.m_pRace));
		m_Level = character.m_Level;
	}
	return *this;
}

void testCopyConstructor(Character c){
	cout << c << endl;
}

int main(){

	Character c("Pedro","Elf",2);

	testCopyConstructor(c);

	Character c2("Josias","Dwarf",7);

	c2 = c;

	return 0;
}
