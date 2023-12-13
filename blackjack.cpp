//TO-DO LIST
//1. Fix the validation while-loop on line 129. If a character is entered, it creates an infinite loop.
//2. Implement a way to decide when an Ace is either an 11 or a 1.
//	 Idea: Store the values of the cards drawn in an array and search for an 11
//	 when appropriate, delete it, and replace it with a 1.
//3. Fix when the dealer should continue drawing on line 151.

//HEADER FILES
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

//FUNCTION PROTOTYPES
void exitProgram();
void letsPlay();
string drawCard(vector<string> &, vector<int> &, int &, int &);
void showDeck(vector<string>, int);	//FOR TESTING

//MAIN FUNCTION THAT DISPLAYS THE WELCOME MESSAGE
int main() {

	srand(time(0));		//SEED THE RANDOM NUMBER GENERATOR
	string playAgain;	//ACCEPTS THE USER RESPONSE TO PLAY

	cout << "****************************" << endl;
	cout << "**                        **" << endl;
	cout << "**  WELCOME TO BLACKJACK  **" << endl;
	cout << "**                        **" << endl;
	cout << "****************************" << endl;

	cout << "\nWould you like to play? (yes/no): ";
	cin >> playAgain;
	
	//VALIDATE RESPONSE INPUT
	while (playAgain != "Yes" && playAgain != "yes" && playAgain != "Y" && playAgain != "y" && playAgain != "No" && playAgain != "no" && playAgain != "N" && playAgain != "n") {
		cout << "Only Enter 'Yes' or 'No': ";
		cin >> playAgain;
	}

	//USE RESPONSE INPUT TO EXIT THE GAME OR START THE GAME
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

//FUNCTION DEFINITION TO START THE GAME
void letsPlay() {
	//PARALLEL VECTORS TO STORE THE NAMES AND VALUES OF THE CARDS
	vector<string> deckOfCards_face{ "Two of Spades", "Three of Spades", "Four of Spades", "Five of Spades", "Six of Spades", "Seven of Spades", "Eight of Spades", "Nine of Spades", "Ten of Spades", "Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Spades",
								 "Two of Hearts", "Three of Hearts", "Four of Hearts", "Five of Hearts", "Six of Hearts", "Seven of Hearts", "Eight of Hearts", "Nine of Hearts", "Ten of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts", "Ace of Hearts",
								 "Two of Clubs", "Three of Clubs", "Four of Clubs", "Five of Clubs", "Six of Clubs", "Seven of Clubs", "Eight of Clubs", "Nine of Clubs", "Ten of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs", "Ace of Clubs",
								 "Two of Diamonds", "Three of Diamonds", "Four of Diamonds", "Five of Diamonds", "Six of Diamonds", "Seven of Diamonds", "Eight of Diamonds", "Nine of Diamonds", "Ten of Diamonds", "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds", "Ace of Diamonds" };
	vector<int> deckOfCards_value{ 2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11,
								   2,3,4,5,6,7,8,9,10,10,10,10,11 };
	
	int size = deckOfCards_face.size();	//SIZE OF THE VECTORS. THE SIZE ADJUSTS WHEN THE DRAWCARD() FUNCTION IS CALLED.

	//RUNNING TOTAL VARIABLES TO KEEP TRACK OF THE DEALER AND PLAYER HANDS.
	//WHEN THE DRAWCARD() FUNCTION IS CALLED, THE APPROPRIATE VARIABLE(HAND) MUST BE HANDED TO THE FUNCTION TO UPDATE THE VARIABLE.
	int dealerHand = 0;
	int playerHand = 0;
	
	//"TWO CARDS" ARE DRAWN FOR THE DEALER
	cout << "\nDealer draws..." << endl;
	cout << drawCard(deckOfCards_face, deckOfCards_value, size, dealerHand) << endl;
	cout << "[Facedown Card]" << endl;
	cout << endl;
	system("pause");

	//TWO CARDS ARE DRAWN FOR THE PLAYER
	cout << "\nYou draw..." << endl;
	cout << drawCard(deckOfCards_face, deckOfCards_value, size, playerHand) << endl;
	cout << drawCard(deckOfCards_face, deckOfCards_value, size, playerHand) << endl;
	cout << endl;
	system("pause");

	//DISPLAY EACH PLAYER'S HAND
	cout << "\nDealer has: " << dealerHand << " + [Facedown card]" << endl;
	cout << "You have: " << playerHand << endl;
	cout << endl;
	system("pause");

	if (playerHand == 21 && dealerHand < 21) {
		cout << "You got 21, YOU WIN! Thanks for playing." << endl;
		exitProgram();
	}

	if (dealerHand == 21 && playerHand < 21) {
		cout << "Dealer got 21, YOU LOSE! Thanks for playing." << endl;
		exitProgram();
	}

	if (playerHand == 21 && dealerHand == 21) {
		cout << "Its a draw! Thanks for playing." << endl;
		exitProgram();
	}
	
	
	//SINCE, TECHNICALLY, ONLY THREE CARDS HAVE BEEN DRAWN AT THIS POINT,
	//WE CAN CALL THE SHOWDECK() FUNCTION WITH OPTION 4 BELOW, AND IT WILL
	//DISPLAY THE DECK WITH A TOTAL OF 49 CARDS.

	//ASK THE PLAYER IF THEY WANT TO HIT OR STAY
	do {
		cout << endl;
		cout << "****************************************" << endl;
		cout << "** What do you want to do?            **" << endl;
		cout << "**   1. Hit me                        **" << endl;
		cout << "**   2. Stay                          **" << endl;
		cout << "**   3. Show deck (for testing)       **" << endl;
		cout << "**   4. Remove a card (for testing)   **" << endl;
		cout << "****************************************" << endl;

		cout << "\nEnter choice: ";
		int actionChoice;
		cin >> actionChoice;
		
		//VALIDATE THE CHOICE
		while (actionChoice != 1 && actionChoice != 2 && actionChoice != 3 && actionChoice != 4) {	//NEEDS TO BE FIXED
			cout << "Only Enter 1 or 2: " << endl;
			cin >> actionChoice;
		}

		//EXECUTE THE CHOICE
		switch (actionChoice) {
		case 1:
			cout << "\nYou drew: ";
			cout << drawCard(deckOfCards_face, deckOfCards_value, size, playerHand) << endl;
			cout << "\nDealer has " << dealerHand << " + [Facedown card]" << endl;
			cout << "You have: " << playerHand << endl;
			system("pause");

			if (playerHand >= 22) {
				cout << "\nYou bust. YOU LOSE!" << endl;
				cout << endl;
				exitProgram();
			}

			break;
		case 2:
			//DEALER REVEALS FACEDOWN CARD
			cout << "\nDealer flips card..." << endl;
			cout << drawCard(deckOfCards_face, deckOfCards_value, size, dealerHand) << endl;
			cout << "\nDealer has: " << dealerHand << endl;
			cout << endl;

			system("pause");

			//EXIT PROGRAM IF DEALER WINS WITH 21
			if (dealerHand == 21) {
				cout << "\nDealer has 21. YOU LOSE!" << endl;
				cout << endl;
				exitProgram();
			}

			//EXIT PROGRAM IF PLAYER HAND IS GREATER THAN DEALER HAND
			if (dealerHand < playerHand && dealerHand >= 17) {
				cout << "YOU WIN!" << endl;
				cout << endl;
				exitProgram();
			}

			//DEALER DRAWS UNTIL NECESSARY
			while (dealerHand < 17) {
				cout << "\nDealer draws..." << endl;
				cout << drawCard(deckOfCards_face, deckOfCards_value, size, dealerHand);
				cout << "\nDealer has: " << dealerHand << endl;
				cout << "Player has: " << playerHand << endl;

				//EXIT PROGRAM IF DEALER WINS WITH 21
				if (dealerHand == 21) {
					cout << "\nDealer has 21. YOU LOSE!" << endl;
					cout << endl;
					exitProgram();
				}

				//EXIT PROGRAM IF DEALER HAND IS GREATER THAN PLAYER HAND
				if (dealerHand > playerHand && dealerHand < 21) {
					cout << "\nDealer hand wins. YOU LOSE!" << endl;
					cout << endl;
					exitProgram();
				}

				//EXIT PROGRAM IF DEALER BUSTS
				if (dealerHand > 21) {
					cout << "\nDealer Busts! YOU WIN!" << endl;
					cout << endl;
					exitProgram();
				}

				//EXIT PROGRAM IF PLAYER HAND IS GREATER THAN DEALER HAND
				if (playerHand > dealerHand) {
					cout << "YOU WIN!" << endl;
					cout << endl;
					exitProgram();
				}
			}
			break;
		
		//FOR TESTING PURPOSES
		case 3: showDeck(deckOfCards_face, size);
				break;
		//FOR TESTING PURPOSES
		case 4: drawCard(deckOfCards_face, deckOfCards_value, size, playerHand);
				break;
		}
	} while (true);
}

//FUNCTION DEFINITION TO EXIT THE GAME
void exitProgram() {
	cout << "See you next time!" << endl;
	exit(0);
}

//FUNCTION DEFINITION THAT REMOVES A CARD FROM THE DECK, ADJUSTS DECK SIZE, ADDS CARD VALUE TO HAND OF PLAYER THAT CALLED THE FUNCTION, AND RETURNS CARD DRAWN FOR OUTPUT.
string drawCard(vector<string> &faceDeck, vector<int> &valueDeck, int &size, int &hand) {
	int cardIndex = rand() % size;	//generate random subscript from the current vector size
	string drawnCard = faceDeck[cardIndex];	//Select random card from the deck and store it in a variable to return
	hand += valueDeck[cardIndex];	//add the card value to the hand total
	faceDeck.erase(faceDeck.begin() + cardIndex);	//remove the card from the card-name deck
	valueDeck.erase(valueDeck.begin() + cardIndex);	//remove the card from the card-value deck
	size -= 1;	//decrease the size of the vectors

	return drawnCard;
}

//FUNCTION DEFINITION FOR DISPLAYING THE CONTENTS OF THE DECK. TESTING PURPOSES.
void showDeck(vector<string> deck, int size) {
	cout << "\nTHE CARDS IN THE DECK ARE: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		cout << deck[i] << endl;
	}
	system("pause");
	cout << endl;
}