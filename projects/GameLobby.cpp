#include <iostream>
#include <string>

/**
 *  Simple Game Lobby
 */

using namespace std;

class Player{

		friend ostream& operator<<(ostream& os, Player& player);
	public:
		Player(string name);
		string getName();

		Player* getNextPlayer();
		void setNextPlayer(Player* player);
	private:
		string name;
		Player* nextPlayer;

};

string Player::getName(){
	return name;
}

Player::Player(string name):
		name(name),
		nextPlayer(0){}

ostream& operator<<(ostream& os, Player& player){
	cout << player.name;
	return os;
}

void Player::setNextPlayer(Player* player){
	nextPlayer = player;
}

Player* Player::getNextPlayer(){
	return nextPlayer;
}

class Lobby{

	friend ostream& operator<<(ostream& os, const Lobby& lobby);
	public:
		Lobby();
		~Lobby();
		void addPlayer();
		void removePlayer();//at the head
		void clear();
	private:
		Player* headPlayer;
		Player* tailPlayer;
};

Lobby::Lobby():
		headPlayer(0),
		tailPlayer(0){}

Lobby::~Lobby(){
	clear();
}

ostream& operator<<(ostream& os, const Lobby& lobby){
	if(lobby.headPlayer != 0){
		int i = 1;
		Player p = *(lobby.headPlayer);

		cout << "Player " << i << ": " <<  p << endl;
		while(p.getNextPlayer() != 0){
			i++;
			p = *(p.getNextPlayer());
			cout << "Player " << i << ": " <<  p << endl;
		}
	}
	return os;
}

void Lobby::addPlayer(){
	string name;

	cout << "What is the player name: ";
	cin >> name;
	Player* player = new Player(name);

	if(headPlayer == 0){
		headPlayer = player;
		tailPlayer = player;
	}else{
		tailPlayer->setNextPlayer(player);
		tailPlayer = player;
	}

	cout << "Player added successfully" << endl;
	cin.clear();
	cin.ignore(10000, '\n');
}

void Lobby::removePlayer(){
	if(headPlayer == 0){
		cout << "There's no player to remove." << endl;
	}else{
		string nameR = headPlayer->getName();
		Player* aux = headPlayer->getNextPlayer();
		delete headPlayer;
		headPlayer = aux;
		cout << nameR << " was removed." << endl;
	}
}

void Lobby::clear(){
	if(headPlayer == 0){
		cout << "The game lobby was already empty." << endl;
	}else{
		cout << "Clearing the lobby" << endl;
		while(headPlayer != 0){
			removePlayer();
		}
		cout << "The game lobby was cleared." << endl;
	}
}

void showMenu(){
	cout << "========Game-Lobby========" << endl;
	cout << "To quit                [0]" << endl;
	cout << "To add a player        [1]" << endl;
	cout << "To remove a player     [2]" << endl;
	cout << "To clear the lobby     [3]" << endl;
	cout << "To see who is online   [4]" << endl;
	cout << "==========================" << endl;
}

int main(){

	Lobby l;
	int cmd;
	do{
		showMenu();
		cout << "Choice: ";
		cin >> cmd;
		switch(cmd){
			case 0:cout << "Before quit . . . ";
				break;
			case 1:
				l.addPlayer();
				break;
			case 2:
				l.removePlayer();
				break;
			case 3:
				l.clear();
				break;
			case 4:
				cout << l << endl;
				break;
		}
	}while(cmd != 0);


	return 0;
}


