#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char BLACKHOLE = ' ';
const int BOARD_SIZE = 9;

enum winners{
	HUMAN,
	COMPUTER,
	TIE,
	NOT_YET
};

void displayBoard(const vector<char>& board);
void showInstructions();
int humanMovement(const vector<char>& board);
int computerMovement(const vector<char>& board);
void processMovement(vector<char>& board, const int to,char player);
int askLocation(string ask, int high, int low = 0);
int whoWon(const vector<char>& board);
bool isLegal(int location,const vector<char>& board);
int swapTurn(int turn);
void announceWinner(int winner);
int proComputerMovement(vector<char> board);

int main(){

	vector<char> board(BOARD_SIZE,BLACKHOLE);
	char start;

	cout << "Welcome to Tic Tac Toe" << endl << endl;
	cout << "Mark by entering its position number" << endl;
	showInstructions();
	cout << "We're going to sort out who started it." << endl;

	do{
		cout << "Do you want to play against:\n Easy Computer type E\n Pro Computer type P\n>";
		cin >> start;
		start = toupper(start);
	}while(start != 'E' && start != 'P');

	srand(static_cast<unsigned int>(time(0)));
	int turn = rand() % 2;

	displayBoard(board);

	cout << "The " << ((turn==HUMAN)?"Human":"Computer") << " has been chosen to start. Good luck!" << endl;

	int winner;
	do{
		if(turn==HUMAN){
			processMovement(board, humanMovement(board), X);
		}else{
			if(start=='E')processMovement(board, computerMovement(board), O);
			else processMovement(board, proComputerMovement(board), O);
		}
		displayBoard(board);
		turn = swapTurn(turn);

		winner = whoWon(board);
	}while(winner == NOT_YET);

	announceWinner(winner);

	return 0;
}

void displayBoard(const vector<char>& board){
	cout << "=================" << endl;
	cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---------" << endl;
	cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---------" << endl;
	cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "---------" << endl;
	cout << "=================" << endl;
}

void processMovement(vector<char>& board, const int to,char player){
	board[to] = player;
}

void showInstructions(){
	cout << " 0 | 1 | 2" << endl;
	cout << " ---------" << endl;
	cout << " 3 | 4 | 5" << endl;
	cout << " ---------" << endl;
	cout << " 6 | 7 | 8" << endl;
}

int computerMovement(const vector<char>& board){
	int choose;
	do{
		choose = rand() % BOARD_SIZE;
	}while(!isLegal(choose,board));

	cout << "Computer: I choose " << choose << endl;
	return choose;
}

int humanMovement(const vector<char>& board){
	int location;

	do{
		location = askLocation("Choose a square",(BOARD_SIZE-1));
	}while(!isLegal(location, board));

	return location;
}

int whoWon(const vector<char>& board){
	const int TOTAL_POSSIBLE = 8;
	const int POSSIBLE_WINS[TOTAL_POSSIBLE][3] = {{0,1,2},
									{3,4,5},
									{6,7,8},
									{0,3,6},
									{1,4,7},
									{2,5,8},
									{0,4,8},
									{2,4,6}};

	for(int possible = 0; possible < TOTAL_POSSIBLE; possible++){
		if((board[POSSIBLE_WINS[possible][0]] != BLACKHOLE) &&
				(board[POSSIBLE_WINS[possible][0]] == board[POSSIBLE_WINS[possible][1]]) &&
				(board[POSSIBLE_WINS[possible][1]] == board[POSSIBLE_WINS[possible][2]])){
			return ((board[POSSIBLE_WINS[possible][0]] == X)?HUMAN:COMPUTER);
		}
	}

	if(count(board.begin(), board.end(), BLACKHOLE) == 0){
		return TIE;
	}

	return NOT_YET;
}

int swapTurn(int turn){
	if(turn == HUMAN)return COMPUTER;
	else return HUMAN;
}

inline bool isLegal(int location,const vector<char>& board){
	return (board[location] == BLACKHOLE);
}

inline int askLocation(string ask, int high, int low){
	int pos;
	do{
		cout << ask << "( " << low << " - " <<  high << " ):";
		cin >> pos;
	}while(pos < low || pos > high);
	return pos;
}

inline void announceWinner(int winner){
	if(winner == HUMAN){
		cout << "Congratulations Human!! You proved the robots won't take the world";
	}else if(winner == COMPUTER){
		cout << "Your computer won. As a gift form, clean its screen";
	}else{
		cout << "There was a draw, no one won";
	}
}

int proComputerMovement(vector<char> board){
	unsigned int pos = 0;
	bool nextStep = false;
	while(!nextStep && pos < BOARD_SIZE){
		if(isLegal(pos,board)){
			board[pos] = O;
			nextStep = (whoWon(board) == COMPUTER);
			board[pos] = BLACKHOLE;
		}
		if(!nextStep){
			pos++;
		}
	}

	if(!nextStep){
		pos = 0;
		while(!nextStep && pos < BOARD_SIZE){
			if(isLegal(pos,board)){
				board[pos] = X;
				nextStep = (whoWon(board) == HUMAN);
				board[pos] = BLACKHOLE;//"Reset" the copy to test again
			}
			if(!nextStep){
				pos++;
			}
		}
	}

	if(!nextStep){
		pos = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
		while(!nextStep && i < BOARD_SIZE){
			pos = BEST_MOVES[i];

			if(isLegal(pos,board)){
				nextStep = true;
			}
			i++;
		}
	}

	cout << "Pro Computer: I choose " << pos << endl;
	return pos;
}
