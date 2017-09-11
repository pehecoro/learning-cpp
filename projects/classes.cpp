#include <iostream>
#include <string>

/**
 * Simple use of Classes
 * 100*level = exp to up
 */

using namespace std;

class Character{
	public:
		Character(string name, string race = "Human",unsigned int level = 1);

		void displayStatus();
		void train();
		void receiveExp(unsigned int exp);

	private:
		string m_name;
		string m_race;
		unsigned int m_level;
		unsigned int m_expBar;

		//Getters
		string getName() const;
		string getRace() const;
		unsigned int getLevel() const;
		unsigned int getBarExp() const;

		//Setters
		void setName(string name);
		void setRace(string race);
		void setLevel(unsigned int level);
		void setBarExp(unsigned int barExp);
};

string Character::getName() const{
	return m_name;
}

string Character::getRace() const{
	return m_race;
}

unsigned int Character::getLevel() const{
	return m_level;
}

void Character::setName(string name){
	m_name = name;
}

Character::Character(string name, string race, unsigned int level):
		m_name(name),
		m_race(race),
		m_level(level),
		m_expBar(0){
	cout << "The character was created" << endl;
}

void Character::displayStatus(){
	cout << "========Status========" << endl;
	cout << "Name: " << m_name << endl;
	cout << "Race: " << m_race << endl;
	cout << "Level: " << m_level << endl;
	cout << "Exp: " << m_expBar  << "(" << (100*m_level) << " to next level)"<< endl;
	cout << "======================" << endl;
}

void Character::train(){
	unsigned int expRandom = rand() % (100 * m_level);
	cout << "==============TRAIN===============" << endl;
	cout << "Congratulations!!" << endl;
	cout << "You received " << expRandom << " of Experience" << endl;
	receiveExp(expRandom);
	cout << "==================================" << endl;
}

void Character::receiveExp(unsigned int exp){
	m_expBar += exp;
	if(m_expBar >= (100*m_level)){
		m_expBar -= (100*m_level);
		m_level++;
		cout << "Level up! now " << m_level << endl;
	}
}

int askCommands(Character& char1){
	int answer;
	cout << "========Commands========" << endl;
	cout << "Type the number to:     " << endl;
	cout << "Show status        - [1]" << endl;
	cout << "Train              - [2]" << endl;
	cout << "Quit               - [3]" << endl;
	cout << "========================" << endl;
	cout << ">";
	cin >> answer;
	if(answer == 1){
		char1.displayStatus();
	}else if(answer == 2){
		char1.train();
	}
	return answer;
}

int main(){
	srand(static_cast<unsigned int>(time(0)));

	Character char1("Pedro");

	while(askCommands(char1) != 3);

}
