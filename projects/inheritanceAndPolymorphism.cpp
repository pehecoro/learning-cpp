#include <iostream>
#include <string>

/**
 * Inheritance and Polymorphism
 */

using namespace std;

int missingSpace(int n, int max){
	int i = 1;

	while(n >= 10){
		n /= 10;
		i++;
	}
	if(i > max)i = max;
	return (max-i);
}

class Monster{

		friend ostream& operator<<(ostream& os, const Monster& monster);
	public:
		Monster(int life = 10, int attack = 10);
		virtual ~Monster();
		void virtual attack() const;
	protected:
		int* m_pLife;
		int* m_pAttack;

};

ostream& operator<<(ostream& os, const Monster& monster){
	cout << "+---------Monster-----------+" << endl;
	cout << "|Life: " << *monster.m_pLife << string(missingSpace(*monster.m_pLife,21),' ') << "|" << endl;
	cout << "|Attack: " << *monster.m_pAttack << string(missingSpace(*(monster.m_pAttack),19),' ') << "|" << endl;
	cout << "+---------------------------+" << endl;
	return os;
}

Monster::Monster(int life, int attack):
	m_pLife(new int(life)),
	m_pAttack(new int(attack))
{}

Monster::~Monster(){
	cout << "[Monster Destructor]" << endl;
	delete m_pLife;
	m_pLife = 0;
	delete m_pAttack;
	m_pAttack = 0;
}

void Monster::attack() const{
	cout << "Rawrrrrr! The monster inflicts " << *m_pAttack << " damage points" << endl;
}

class Ghost: public Monster{

	public:
		Ghost(int life = 10, int attack = 10, int frightLevel = 1);
		~Ghost();
		void virtual attack() const;//virtual is optional
		void daunt() const;
	protected:
		int* m_pFrightLevel;
};

Ghost::Ghost(int life, int attack, int frightLevel):
	Monster::Monster(life,attack),
	m_pFrightLevel(new int(frightLevel)){}

Ghost::~Ghost(){
	cout << "[Ghost destructor]" << endl;
	delete m_pFrightLevel;
	m_pFrightLevel = 0;
}

void Ghost::attack() const{
	cout << "Booooooo.. The ghost inflicts " << *m_pAttack <<" damage points" << endl;
}

void Ghost::daunt() const{
	if(*(m_pFrightLevel) == 1){
		cout << "~~~~ You hear a distant noise ~~~~" << endl;
	}else if(*(m_pFrightLevel) == 2){
		cout << "~~~~ You feel a chill ~~~~" << endl;
	}else{
		cout << "~~~~ You hear a noise in your ear ~~~~~" << endl;
	}
}

void invokeMonster(){
	cout << "Invoking a monster" << endl;
	Monster m(1,3);
	cout << m;
	m.attack();
}

void invokeGhost(){
	cout << "\nInvoking a ghost" << endl;
	Ghost g(11,4);
	cout << g;
	g.attack();
	g.daunt();
}

void invokeGhostLikeAMonster(){
	cout << "\nInvoking Ghost like a Monster" << endl;
	Monster* m = new Ghost();
	cout << *m;
	m->attack();
	delete m;
}

int main(){

	invokeMonster();

	invokeGhost();

	invokeGhostLikeAMonster();

	return 0;
}
