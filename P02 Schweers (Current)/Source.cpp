// ***************************************************************
// Author: Gabriela Schweers
// Date: 12/6/21
// Description: A menu-driven combat simulator. Features an attack
// function and a heal function. Played against an AI enemy.
// ****************************************************************

// LIBRARIES AND EXTERNAL DEPENDENCIES
#pragma warning(disable:6031)							// disables "return value ignored..."
#include <iostream>										// for cout, cin (I/O)
#include <conio.h>										// for _getch()
#include <iomanip>										// for setprecision()
#include "CIS115-P02S - Menu Driven Combat Simulator.h" // including header file

// CONSTANTS
#define TRUE			1
#define FALSE			0
#define MENU_LOWEST		1
#define MENU_HIGHEST	2
#define MENU_ATTACK		1
#define MENU_HEAL		2


// FUNCTION PROTOTYPES
void attack(int&); 
void enemyAttack(int&);
void heal(int&);
void enemyHeal(int&);

// MAIN
using namespace std;
int main() {
	// VARIABLE DECLARATION AND INITIALIZATION
	int menuChoice = 0; // holds user menu choice (attack or heal)
	int hpEnemy = 100;	// holds enemy's health points (starts at 100)
	int hpUser = 100;	// holds user's health points (starts at 100)

	SeedRNGToSystemClock();

	while (hpUser > 0 && hpEnemy > 0) {				// (loops while enemy and user's HP are above 0, ends when either is defeated)
		// MENU
		cout << "Player HP: " << hpUser << endl;	// displaying user HP
		cout << "Enemy HP: " << hpEnemy << endl;	// displaying enemy HP

		// USER INPUT
		cout << "Select an action..." << endl;
		cout << "1.) Atack" << endl;
		cout << "2.) Heal" << endl;
		cout << ": ";
		cin >> menuChoice;							// ...storing into menuChoice

		// INPUT VALIDATION
		while (cin.fail() == TRUE || menuChoice > MENU_HIGHEST || menuChoice < MENU_LOWEST) {
			if (cin.fail()) {						// if menuChoice not an int...
				cout << "That is not a numerical choice.";
			} else {								// else... menuChoice out of range
				cout << "That choice does not exist.";
			}
			cout << " Please try again..." << endl;
			cin.clear();							// clearing cin flags
			rewind(stdin);							// purge keyboard buffer
			// REPROMPT
			cout << "Select an action..." << endl;	// asking for user input
			cout << "1.) Atack" << endl;
			cout << "2.) Heal" << endl;
			cout << ": ";
			cin >> menuChoice;						// ...storing into menuChoice
		}

		/* MENU CHOICE ACTIONS */
		if (menuChoice == MENU_ATTACK) {			// if menuChoice = 1
			attack(hpEnemy);						// user attacks enemy, hpEnemy is updated
			enemyAttack(hpUser);					// enemy attacks user always if user picks attack, hpUser is updated
			if (hpUser > 0 && hpEnemy > 0) {		// if both are still alive, pause then clear screen
				_getch();							
				ClearScreen();						
			} else {										// when someone is defeated...
				if (hpUser <= 0 && hpEnemy > 0) {			// if user loses...
					cout << "The enemy has defeated you. So sad. :(" << endl;
					_getch(); 
				} else if (hpUser > 0 && hpEnemy <= 0) {	// if user wins...
					cout << "You have defeated the enemy. Congrats! :)" << endl;
					_getch();
				}
			}
		} if (menuChoice == MENU_HEAL) {					// if menuChoice = 2
			heal(hpUser);									// updates hpUser by heal amt
			int enemyAttackOrHeal = generateRandomValue(1, 10);
			if (enemyAttackOrHeal >= 5) {					// enemy has chance to either attack or heal ONLY WHEN USER HEALS
				enemyAttack(hpUser);
			} else if (enemyAttackOrHeal < 5) {
				enemyHeal(hpEnemy);
			}
			_getch(); 
			ClearScreen(); 
		}
	}
	
	// END OF GAME
	cout << endl;
	cout << "GAME OVER." << endl;

	// EXIT TO OS
	_getch();
	return 0;
}

// FUNCTION DEFINTIONS
/* ATTACK FUNCTION (menuChoice = 1) */
void attack(int& hpEnemy) {
	// LOCAL VARS
	int attackValRand;											// holds rand value of damage dealt
	int attackRand = generateRandomValue(1, 100);

	if (attackRand > 80) {										// if attack misses...
		cout << "You ATTACK and MISS." << endl;
		hpEnemy = hpEnemy - 0;									// updating hpEnemy by nothing (missed)
	}
	else {														// else... attack lands
		attackRand = generateRandomValue(1, 100);				// resetting random num generator (20% chance of crit)
		attackValRand = generateRandomValue(1, 10);				// initializing attackValRand (attack dmg from 1-10)

		if (attackRand < 80) {									// normal hit, any int below 80...
			cout << "You ATTACK and score a HIT on the enemy for " << attackValRand << "HP." << endl;
			hpEnemy = hpEnemy - attackValRand;					// updates health of enemy
		} else {												// critical hit, any int above 80...
			attackValRand = (int)((attackValRand * 2.5) + 5);	// casting to int, avoiding possible decimal nums
			cout << "You ATTACK and score a CRITICAL HIT on the enemy for " << attackValRand << "HP." << endl;
			hpEnemy = hpEnemy - attackValRand;					// updates health of enemy
		}
	}
}

/* ENEMY ATTACK (after every attack and heal user does) */
void enemyAttack(int& hpUser) {
	// LOCAL VARS
	int enemyAttackValRand;										// holds rand dmg amount 1-10
	int enemyAttackRand = generateRandomValue(1, 100);			// rand number 1-100 for 20% chance attack misses

	if (enemyAttackRand > 80) { // attack misses...
		cout << "The enemy attacks and MISSES." << endl;
		hpUser = hpUser - 0; // updates hpUser
	} else { // attack lands...
		enemyAttackValRand = generateRandomValue(1, 10);		// initializing enemyAttackValRand (attack dmg from 1-10)
		cout << "The enemy attacks and scores a HIT on you for " << enemyAttackValRand << "HP." << endl;
		hpUser = hpUser - enemyAttackValRand;					// updates health of user
	}
}

/* HEAL FUNCTION (menuChoice = 2) */
void heal(int& hpUser) {
	// LOCAL VARS
	int healVal = generateRandomValue(3, 25);					// holds rand amount that user can heal from 3-25

	cout << "You heal yourself for " << healVal << "HP." << endl; 
	hpUser = hpUser + healVal;									// updates health of user
}

/* HEAL FUNCTION FOR ENEMY */
void enemyHeal(int& hpEnemy) {
	// LOCAL VARS
	int enemyHealVal = generateRandomValue(3, 25);				// holds rand amount that user can heal from 3-25

	cout << "The enemy heals for " << enemyHealVal << "HP." << endl;
	hpEnemy = hpEnemy + enemyHealVal;							// updates health of enemy
}
