#ifndef _ITEM7_
#define _ITEM7_

#include <iostream>

class Character {

public:
	Character(){
		std::cout << "Constructor Character" << std::endl;
	}
	virtual ~Character(){
		std::cout << "Destructor Character" << std::endl;
	}
	virtual void talk() {
		std::cout << "Hi" << std::endl;
	}

};

class NPC : public Character {

public:
	NPC() {
		std::cout << "Constructor NPC" << std::endl;
	}
	~NPC() {
		std::cout << "Destructor NPC" << std::endl;
	}
	virtual void talk() {
		std::cout << "Hello" << std::endl;
	}

};

Character* getCharacter() {
	return new NPC();
}


void testItem7(){

	{
		Character* n = getCharacter();
		delete n;
	}

}


#endif