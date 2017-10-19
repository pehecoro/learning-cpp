#ifndef _ITEM10_
#define _ITEM10_

#include <iostream>
#include <string>

class Item {

private:
	std::string description;
	float sellPrice;

public:
	Item(const std::string& _description, const float& _sellPrice)
		: description(_description), sellPrice(_sellPrice) {}
	~Item() {}
	Item& operator=(const Item& item) {
		description = item.description;
		sellPrice = item.sellPrice;

		return *this;
	}
	std::string& getDescription() {
		return description;
	}
	float& getSellPrice(){
		return sellPrice;
	}
};

void testItem10() {

	Item i("Apple", 1.2f);

	std::cout << i.getDescription() << " : " << i.getSellPrice() << std::endl;

	Item it("Sword", 7.5f);

	i = it;

	std::cout << i.getDescription() << " : " << i.getSellPrice() << std::endl;

}



#endif