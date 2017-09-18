#include <iostream>
#include <string>
#include <vector>

/*
	Simple "quest system"
*/

class Item {

	friend std::ostream& operator<<(std::ostream& os, const Item& item);
private:
	std::string name;
	std::string description;

public:
	Item(std::string name, std::string description = ""): name(name){}

	const std::string& getName() const{
		return name;
	}
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
	os << item.name;
	return os;
}

struct BagItem {
	Item item;
	unsigned int units;
};

class Quest {

	friend std::ostream& operator<<(std::ostream& os, const Quest& quest);
private:
	std::string name;
	std::string description;
	std::vector<BagItem> requirements;
	std::vector<BagItem> reward;

public:
	Quest(std::string name, std::string description, std::vector<BagItem>& requirements, std::vector<BagItem>& reward)
		:name(name), description(description), requirements(requirements), reward(reward) {}

	const std::string& getDescription() const {
		return description;
	}
	void setDescription(const std::string description) {
		this->description = description;
	}
	void addRequirement(const BagItem req) {
		requirements.push_back(req);
	}
	void addReward(const BagItem rew) {
		reward.push_back(rew);
	}

	std::vector<BagItem>& getRequirements() {
		return requirements;
	}
};

std::ostream& operator<<(std::ostream& os, const Quest& quest) {
	os << quest.name;
	return os;
}

class Player {

private:
	std::string name;
	int level;
	std::vector<BagItem> inventory;
	std::vector<Quest> quests;

public:
	Player(std::string name) :name(name), level(1){}

	void receiveQuest(const Quest quest) {
		quests.push_back(quest);
	}

	void receiveItem(const BagItem item) {
		inventory.push_back(item);
	}

	std::vector<BagItem>& getInventory() {
		return inventory;
	}

	std::vector<Quest>& getQuests() {
		return quests;
	}

};

Item createItem() {
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::string name, description;
	std::cout << "+------------New Item-------------+" << std::endl;
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << "Description: ";
	std::getline(std::cin, description);
	return Item(name, description);
}

void showItems(const std::vector<BagItem>& items){
	for (std::vector<BagItem>::const_iterator it = items.begin();
		it != items.end(); it++) {
		std::cout << "| " << (it->item) << " Quantity: " << (it->units) << std::endl;
	}
}

template <typename T>
void showOptions(const std::vector<T>& options) {
	for (std::vector<T>::const_iterator it = options.begin();
		it != options.end(); it++) {
		std::cout << (*it) << "  [" << it - options.begin() << "]" << std::endl;
	}
}

BagItem addQuestItem(const std::vector<Item>& itemsCreated) {
	unsigned int itemId, qty;
	std::cout << "+------------Add Item-------------+" << std::endl;
	showOptions(itemsCreated);
	do {
		std::cout << "> ";
		std::cin >> itemId;
	} while (itemId >= itemsCreated.size());
	do {
		std::cout << "Quantity: ";
		std::cin >> qty;
	} while (qty < 0);
	BagItem item = { Item(itemsCreated[itemId]),qty };
	return item;
}

Quest createQuest(const std::vector<Item>& itemsCreated) {
	int cmd;
	std::string description, name;
	std::vector<BagItem> requirements;
	std::vector<BagItem> rewards;
	std::cin.clear();
	std::cout << "Name: ";
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << "Description:";
	std::getline(std::cin, description);
	do {
		std::cout << "+---------Create Quest--------+" << std::endl;
		std::cout << "|Name: " << name << std::endl;
		std::cout << "|Description: " << description << std::endl;
		std::cout << "|Requirement: " << std::endl;
		showItems(requirements);
		std::cout << "|Reward: " << std::endl;
		showItems(rewards);
		std::cout << "|_____________________________|" << std::endl;
		std::cout << "|                             |" << std::endl;
		std::cout << "| Add Item Required       [1] |" << std::endl;
		std::cout << "| Add Reward Item         [2] |" << std::endl;
		std::cout << "|                             |" << std::endl;
		std::cout << "| Done                    [0] |" << std::endl;
		std::cout << "+-----------------------------+" << std::endl;
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == 1) {
			requirements.push_back(addQuestItem(itemsCreated));
		}else if (cmd == 2) {
			rewards.push_back(addQuestItem(itemsCreated));
		}
	} while (cmd != 0);
	return Quest(name, description, requirements, rewards);
}

Quest receiveQuest(const std::vector<Quest>& quests) {
	unsigned int questId;
	std::cout << "+---------Receive Quest--------+" << std::endl;
	std::cout << "|Type the number of the quest  |" << std::endl;
	std::cout << "|Quests Available:             |" << std::endl;
	showOptions(quests);
	std::cout << "|______________________________|" << std::endl;
	do {
		std::cout << ">";
		std::cin >> questId;
	} while (questId >= quests.size());
	return quests.at(questId);
}

BagItem receiveItem(const std::vector<Item>& items) {
	unsigned int itemId, qty;
	std::cout << "+---------Receive Item--------+" << std::endl;
	std::cout << "|Type the number of the item   |" << std::endl;
	std::cout << "|Items available:              |" << std::endl;
	showOptions(items);
	std::cout << "|______________________________|" << std::endl;
	do {
		std::cout << ">";
		std::cin >> itemId;
	} while (itemId >= items.size());
	std::cout << "Quantity: ";
	std::cin >> qty;
	BagItem bagItem = { items.at(itemId),qty };
	return bagItem;
}

void showInventory(Player& p) {
	std::cout << "+---------Inventory--------+" << std::endl;
	showItems(p.getInventory());
	std::cout << "+--------------------------+" << std::endl;
}

void completeQuest(Player& p) {
	unsigned int questId;
	bool success = false;
	std::cout << "+---------Complete Quest---------+" << std::endl;
	std::cout << "|Type the number of the quest    |" << std::endl;
	std::cout << "|Quests:                         |" << std::endl;
	showOptions(p.getQuests());
	std::cout << "|________________________________|" << std::endl;
	do {
		std::cout << ">";
		std::cin >> questId;
	}while (questId >= p.getQuests().size());
	//success = tryCompleteQuest(p,questId);
	if (success) {
		std::cout << "Congratulations! You completed the quest";
	}
	else {
		std::cout << "Sorry, you don't have the requirements";
	}
}



int main() {
	int cmd;
	std::vector<Item> itemsCreated;
	std::vector<Quest> questsCreated;
	std::string name;
	std::cout << "What is your name stranger?" << std::endl;
	std::cin >> name;
	Player p(name);
	std::cout << "Welcome " << name << std::endl;

	do {
		std::cout << "+------------Menu-------------+" << std::endl;
		std::cout << "| Create an Item          [1] |" << std::endl;
		std::cout << "| Create a Quest          [2] |" << std::endl;
		std::cout << "| Receive a Quest         [3] |" << std::endl;
		std::cout << "| Get an Item             [4] |" << std::endl;
		std::cout << "| See inventory           [5] |" << std::endl;
		std::cout << "| Complete a Quest        [6] |" << std::endl;
		std::cout << "|                             |" << std::endl;
		std::cout << "| Leave                   [0] |" << std::endl;
		std::cout << "+-----------------------------+" << std::endl;
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == 1) {
			itemsCreated.push_back(createItem());
		}
		else if (cmd == 2) {
			questsCreated.push_back(createQuest(itemsCreated));
		}
		else if (cmd == 3) {
			p.receiveQuest(receiveQuest(questsCreated));
		}
		else if (cmd == 4) {
			p.receiveItem(receiveItem(itemsCreated));
		}
		else if (cmd == 5) {
			showInventory(p);
		}
		else if (cmd == 6) {
			//completeQuest(p);
		}
	} while (cmd != 0);

	return 0;
}