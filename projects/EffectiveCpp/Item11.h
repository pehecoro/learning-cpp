#ifndef _ITEM11_
#define _ITEM11_

#include <iostream>
#include <string>

struct Slot {
	std::string desc;
	int amo;
	Slot(const std::string& _desc, const int& _amo)
		: desc(_desc), amo(_amo) {}
	Slot(const Slot& slot) : desc(slot.desc), amo(slot.amo) {}
};


class Bag {

private:
	Slot* slot;

public:
	Bag(Slot* _slot) : slot(_slot){}
	~Bag() {
		delete slot;
	}
	Bag& operator=(const Bag& bag) {

		Slot* pSlot = pSlot = new Slot(*bag.slot);

		delete slot;

		slot = pSlot;

		return *this;
	}
	Slot& getSlot() {
		return *slot;
	}
};

void testItem11() {

	Bag bag(new Slot("Apple", 2));

	std::cout << bag.getSlot().desc << " : " << bag.getSlot().amo << std::endl;

	Bag bag2(new Slot("Sword", 1));

	bag = bag2;

	std::cout << bag.getSlot().desc << " : " << bag.getSlot().amo << std::endl;

}

#endif