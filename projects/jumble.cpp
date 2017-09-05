#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


/**
 * Word Jumble - Puzzle Game
 */

using namespace std;

void showMenu();
string startPuzzle();

const short int NUM_WORDS = 6;

enum fields{
	WORD,//0
	HINT,//1
	NUM_FIELDS//2
};

const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"illidan", "Are you prepared to reject the Light?"},
		{"jaina", "Do you have some relationship problems?"},
		{"kael", "Bright and stylish"},
		{"chen", "Another drink please!"},
		{"kel'thuzad", "It is cold here, isn't it?"},
		{"medivh","What is this green thing on your lips?"}
};

int main(){
	cout << "\t Welcome to Word Jumble" << endl;
	cout << "\nUnscramble the letters to make a word" << endl;

	string cmd = "";
	while(cmd != "quit"){
		showMenu();
		cmd = startPuzzle();
	}

	cout << "Closing . . ." << endl;

	return 0;
}

void showMenu(){
	cout << "#####################################" << endl;
	cout << "To get a hint          type    'hint'" << endl;
	cout << "To quit                type    'quit'" << endl;
	cout << "To restart             type 'restart'" << endl;
	cout << "#####################################" << endl;
}

string startPuzzle(){

	string answer = "";

	srand(static_cast<unsigned int>(time(0)));
	int choice = rand() % NUM_WORDS;

	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	string jumble = theWord;

	int length = jumble.size();

	for(int i = 0; i < length; ++i){
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "Jumble: " << jumble << endl;
	cout << "Guess: ";
	cin >> answer;

	while(answer != theWord && answer != "quit" && answer != "restart"){
		if(answer == "hint"){
			cout << "Hint: " << theHint;
		}else{
			cout << "It's not correct. Try again =)";
		}

		cin.clear();
		cin.ignore(10000,'\n');
		cout << "\nGuess: ";
		cin >> answer;

	}

	if(answer == theWord){
		cout << "#####################################\n"
				"####  Congratulations, you won!  ####\n"
				"#####################################" << endl;
	}

	return answer;
}
