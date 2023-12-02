#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int exitProgram();
void letsPlay();
int getRandNum();
void hitMe();

int dealerHand = 0;
int playerHand = 0;

string const deckOfCards_face[52] = {"Two of Spades", "Three of Spades", "Four of Spades", "Five of Spades", "Six of Spades", "Seven of Spades", "Eight of Spades", "Nine of Spades", "Ten of Spades", "Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Spades",
									 "Two of Hearts", "Three of Hearts", "Four of Hearts", "Five of Hearts", "Six of Hearts", "Seven of Hearts", "Eight of Hearts", "Nine of Hearts", "Ten of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts", "Ace of Hearts",
									 "Two of Clubs", "Three of Clubs", "Four of Clubs", "Five of Clubs", "Six of Clubs", "Seven of Clubs", "Eight of Clubs", "Nine of Clubs", "Ten of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs", "Ace of Clubs",
									 "Two of Diamonds", "Three of Diamonds", "Four of Diamonds", "Five of Diamonds", "Six of Diamonds", "Seven of Diamonds", "Eight of Diamonds", "Nine of Diamonds", "Ten of Diamonds", "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds", "Ace of Diamonds"};
int const deckOfCards_value[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11};

int main() {

	srand(time(0));

	cout << "****************************" << endl;
	cout << "**                        **" << endl;
	cout << "**  WELCOME TO BLACKJACK  **" << endl;
	cout << "**                        **" << endl;
	cout << "****************************" << endl;

	cout << "\nWould you like to play? (yes/no): ";
	string playAgain;
	cin >> playAgain;
	while (playAgain != "Yes" && playAgain != "yes" && playAgain != "Y" && playAgain != "y" && playAgain != "No" && playAgain != "no" && playAgain != "N" && playAgain != "n") {
		cout << "Only Enter 'Yes' or 'No': ";
		cin >> playAgain;
	}

	if (playAgain == "No" || playAgain == "no" || playAgain == "N" || playAgain == "n") {
		exitProgram();
	}
	else {
		cout << "Alright, Lets play!" << endl;
		cout << endl;
		system("pause");
		letsPlay();
	}

	return 0;
}

int exitProgram() {
	cout << "See you next time!" << endl;
	return 0;
}

int getRandNum() {
	int randNum = rand() % 52;
	return randNum;
}

void letsPlay() {
	
	int dealerFirstCard = getRandNum();
	int dealerSecondCard = getRandNum();
	int dealerThirdCard = getRandNum();
	int dealerFourthCard = getRandNum();

	int playerFirstCard = getRandNum();
	int playerSecondCard = getRandNum();
	int playerThirdCard = getRandNum();
	int playerFourthCard = getRandNum();
	
	cout << "\nDealer draws..." << endl;
	cout << deckOfCards_face[dealerFirstCard] << endl;
	cout << deckOfCards_face[dealerSecondCard] << endl;
	dealerHand += (deckOfCards_value[dealerFirstCard] + deckOfCards_value[dealerSecondCard]);
	cout << endl;
	system("pause");

	cout << "\nYou draw..." << endl;
	cout << deckOfCards_face[playerFirstCard] << endl;
	cout << deckOfCards_face[playerSecondCard] << endl;
	playerHand += (deckOfCards_value[playerFirstCard] + deckOfCards_value[playerSecondCard]);
	cout << endl;
	system("pause");

	cout << "\nDealer has: " << dealerHand << endl;
	cout << "You have: " << playerHand << endl;
	cout << endl;
	
	cout << "*****************************" << endl;
	cout << "** What do you want to do? **" << endl;
	cout << "**        1. Hit me        **" << endl;
	cout << "**        2. Stay          **" << endl;
	cout << "*****************************" << endl;

	int actionChoice;
	cin >> actionChoice;
	while (actionChoice != 1 && actionChoice != 2) {	//NEEDS TO BE FIXED
		cout << "Only Enter 1 or 2: " << endl;
		cin >> actionChoice;
	}

	switch (actionChoice) {
	case 1:	
		hitMe();
		break;
	case 2:
		cout << "You chose 2";
		break;
	}

}

void hitMe() {
	int drawCard = getRandNum();
	cout << "You drew: " << deckOfCards_face[drawCard] << endl;
	playerHand += deckOfCards_value[drawCard];
	cout << "You have: " << playerHand << endl;

}