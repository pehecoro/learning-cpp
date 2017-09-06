#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>

/**
 *  Hangman Program
 */

using namespace std;

vector<string> words = {"WORD","FIRE","ELF","SHIELD"};

const int MAX_INCORRECT = 8;
int miss = 0;
string rightWord, usedLetters;
string tentativeWord;

void verify(char guess);

int main(){

	char guess;

	cout << "Welcome to Hangman Program" << endl;

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	rightWord = words[0];
	tentativeWord = string(rightWord.size(),'-');

	while(miss < MAX_INCORRECT && tentativeWord != rightWord){
		cout << "You have " << (MAX_INCORRECT-miss) << " incorrect guesses left." << endl;
		cout << "Letters already used: " << usedLetters << endl;
		cout << "Word:\n" << tentativeWord << endl;
		cout << "Guess:";
		cin >> guess;
		guess = toupper(guess);
		verify(guess);
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if(tentativeWord == rightWord){
		cout << "Congratulations! You guessed it! =)" << endl;
	}else{
		cout << "You've been hanged!" << endl;
	}
	cout << "Word: " << rightWord << endl;

	return 0;
}

void verify(char guess){
	if(usedLetters.find(guess) == string::npos){

		usedLetters+=guess;//Save letter

		if(rightWord.find(guess) == string::npos){
			cout << "You missed =(" << endl;
			miss++;
		}else{
			for(unsigned int i = 0; i < rightWord.size(); i++){
				if(rightWord[i] == guess){
					cout << "Great!" << endl;
					tentativeWord[i] = guess;
				}
			}
		}
	}
}
