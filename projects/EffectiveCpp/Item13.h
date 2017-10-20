#ifndef _ITEM13_
#define _ITEM13_

#include <iostream>
#include <string>
#include <memory>


class Armor {

private:
	std::string desc;
	float sellPrice;

public:
	Armor(const std::string& _desc, const float& _sellPrice)
		: desc(_desc), sellPrice(_sellPrice) 
	{
		std::cout << "Armor Constructor\n";
	}
	~Armor() 
	{
		std::cout << "Armor Destructor\n";
	}

};

Armor* createArmor() {
	return new Armor("Default", 0.0f);
}

void x() {

	std::shared_ptr<Armor> pArmor(createArmor());//Manage resources

	//Do things

} //delete



void testItem13() {

	x();

}


#endif