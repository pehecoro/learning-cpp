#ifndef _ITEM12_
#define _ITEM12_

#include <iostream>

class Enemy {

private:
	float atk;
public:
	Enemy(const float& _atk) : atk(_atk){}
	Enemy(const Enemy& enemy) : atk(enemy.atk) 
	{
		std::cout << "Enemy copy constructor\n";
	}
	virtual ~Enemy(){}
	virtual void taunt() {
		std::cout << "Grrrr\n";
	}
	Enemy& operator=(const Enemy& enemy) {
		atk = enemy.atk;

		return *this;
	}
	float& getAtk() {
		return atk;
	}
};


class Boss : public Enemy {

private:
	float def;
public:
	Boss(const float& _def, const float& _atk = 10) : Enemy(_atk), def(_def){}
	Boss(const Boss& boss) : Enemy(boss), def(boss.def) 
	{
		std::cout << "Boss copy constructor\n";
	}
	~Boss(){}
	virtual void taunt() {
		std::cout << "Feel my power!\n";
	}
	Boss& operator=(const Boss& boss) {
		std::cout << "Boss copy assignment \n";
		Enemy::operator=(boss);

		def = boss.def;

		return *this;
	}
	float getDef() const{
		return def;
	}

};


void testItem12() {

	{
		Boss b1(20, 15);
		Boss b2(10);

		std::cout << "Boss1 -  Atk: " << b1.getAtk() <<  " Def: " << b1.getDef() << '\n';
		std::cout << "Boss2 -  Atk: " << b2.getAtk() << " Def: " << b2.getDef() << '\n';

		b1 = b2;

		std::cout << "Boss1 -  Atk: " << b1.getAtk() << " Def: " << b1.getDef() << '\n';
		std::cout << "Boss2 -  Atk: " << b2.getAtk() << " Def: " << b2.getDef() << '\n';

	}

}

#endif
