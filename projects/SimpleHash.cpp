#include <iostream>
#include <memory>
#include <string>

/*
	Simple Hash?
*/

struct Item{
	std::string desc;
	float price;
};

class MyHash {

private:
	enum{SIZE = 10};

	std::shared_ptr<Item> list[SIZE];

public:
	MyHash() {}
	~MyHash(){}

	unsigned int hashItem(const std::string& desc) {
		unsigned int num = 0;
		for (std::string::const_iterator it = desc.begin(); it != desc.end(); ++it) {
			num += static_cast<int>(*it);
		}
        return num;
	}

	bool insert(const Item& item) {
        unsigned int num = hashItem(item.desc);
		unsigned int i = 0;
		for (; list[(num + i)%SIZE] != nullptr && i < SIZE; ++i){
			if(list[(num + i)%SIZE]->desc == item.desc){
				return false;
			}
		}
		if(list[(num + i)%SIZE] == nullptr){
			list[(num + i)%SIZE] = std::make_shared<Item>(item);
			return true;
		}
		return false;
	}

	void show(){
		for(int i = 0; i < SIZE; ++i){
			if(list[i] != nullptr)std::cout << "[" << i << "]:" << list[i]->desc << std::endl;
		}
	}

	const Item* search(std::string desc){
		unsigned int num = hashItem(desc);
		int i = 0;
		for(; list[(num+i)%SIZE]->desc != desc && i < SIZE; ++i);
		if(i==SIZE){//Not found
			return nullptr;
		}
		return list[(num+i)%SIZE].get();
	}

	bool remove(std::string desc){
		unsigned int num = hashItem(desc);
		int i = 0;
		for(; list[(num+i)%SIZE]->desc != desc && i < SIZE; ++i);
		if(i==SIZE){//Not found
			return false;
		}

		list[(num+i)%SIZE].reset();
		return true;
	}

};

int main(){

	MyHash mH;

	mH.insert({"Sword",12.3f});
	mH.insert({"Apple",3.3f});
	mH.insert({"Stone",0.7f});

	mH.show();

	std::cout << "Sword price: " << mH.search("Sword")->price << std::endl;

	std::cout << "Removing Sword . . . " << std::endl;

	mH.remove("Sword");
	mH.show();

	std::cout << "Inserting Sword . . ." << std::endl;
	mH.insert({"Sword",12.3f});

	mH.show();

	std::cin.get();

    return 0;
}
