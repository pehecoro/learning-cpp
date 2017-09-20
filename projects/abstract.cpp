#include <iostream>
#include <string>

/**
 * Abstract class
 */

using namespace std;

class Enemy{

		friend ostream& operator<<(ostream& os, const Enemy& enemy);
	public:
		Enemy(int atk);
		virtual ~Enemy();
		virtual void taunt() const = 0; // pure virtual, so this is an abstract class
		virtual void attack() const;

	protected:
		int m_Attack;

};

ostream& operator<<(ostream& os, const Enemy& enemy){
	enemy.taunt();
	return os;
}

Enemy::Enemy(int atk):
	m_Attack(atk)
{}

Enemy::~Enemy(){}

void Enemy::attack() const{
	cout << "The enemy inflicts " << m_Attack << " damage points." << endl;
}

class Boss: public Enemy{

	public:
		Boss(int atk = 10, int multiplier = 2);
		void virtual taunt() const;
		void virtual attack() const;
	protected:
		int m_Multiplier;

};

Boss::Boss(int atk, int multiplier):
	Enemy(atk), m_Multiplier(multiplier)
{}


inline void Boss::taunt() const{
	cout << "Come and feel the fury of the guardian of the fire" << endl;
}

inline void Boss::attack() const{
	cout << "The Guardian of the Fire inflicts " << (m_Attack*m_Multiplier)
			<< " damage points" << endl;
}

class FinalBoss: public Boss{
	public:
		FinalBoss(int constantFire):
			m_ConstantFire(constantFire){}

		void virtual taunt() const{
			cout << "I am an elemental lord, you WILL obey me!" << endl;
		}

		void virtual attack() const{
			cout << "You had better be ready, minion. The Firelord inflicts "
					<< m_Attack*m_Multiplier+m_ConstantFire << " damage points" << endl;
		}

		void specialAttack() const{
			cout << "Prepare to your death. The Firelord inflicts "
					<< m_Attack*m_Multiplier*m_ConstantFire << " damage points" << endl;
		}
	private:
		int m_ConstantFire;

};

void invokeBoss(){
	cout << "+-------------Invoking Boss-----------+" << endl;
	Enemy* boss = new Boss();
	cout << (*boss) << endl;
	boss->attack();
	delete boss;
	cout << "+-------------------------------------+" << endl;
}

void invokeFinalBoss(){
	cout << "+---------Invoking Final Boss---------+" << endl;
	FinalBoss finalBoss(10);
	cout << finalBoss << endl;
	finalBoss.attack();
	finalBoss.specialAttack();
	cout << "+-------------------------------------+" << endl;
}

int main(){

	invokeBoss();

	invokeFinalBoss();

	return 0;
}

