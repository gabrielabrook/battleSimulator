// **************************************************************
// Author: Gabriela Schweers
// Date: 12/6/21
// Description: PSEUDOCODE for the Menu-Driven Combat simulator.
// Planning for layout of code, functionsvars, and more needed.
// **************************************************************


// LIBRARIES AND EXTERNAL DEPENDECIES
// include iostream (cout, cin (I/O))
// include conio.h (_getch())
// include iomanip (setprecision())
// using namespace std

// CONSTANT SETUP
// define true and false
// define menu lowest val and highest val (avoiding magic nums)
// define which int means menu attack and which means menu heal

// PROTOTYPES (FUNCTION DECLARATION)
// void attack(int&) - holds all calculations, menu choice #1 (& for all for pass-by reference)
// void enemyAttack(int&) - holds basic attack style for enemy, called after choice 1 & 2
// void heal(int&) - holds all calculations, menu choice #2
// void enemyHeal(int&) - allows enemy to heal, intended to only be possible when user heals

int main() {
	/*
		// DECLARE VARS
		int menuChoice - holds users choice in menu
		float hpUser - holds user's health points
		float hpEnemy - holds enemy's health points

		// While Loop(while user's or enemy's health are above zero, continue displaying menu) {
			// MENU
			print out hpUser and hpEnemy (gets updated by funct calls)

			prints out menu message and promps for user input
			two choices: 1.) attack
						 2.) heal
			...stores into menuChoice

			// INPUT VALIDATION FOR menuCHOICE
			while cin flag is up and menuChoice out of range... {	(NESTED WHILE LOOP)
				if(cin.fail()) { (not an int)
				print error message (no endl)
				} else { (out of range)
				print error message (no endl)
				}
				clear cin flags and purge keyboard buffer
				print try again message
				reprompt
				store in menuChoice
			}

			// MENU CHOICE ACTIONS
			if(menu attack = 1, user attacks) {
				attack(hpEnemy) calls attack fucnt, updates hpEnemy (int& value passed thru)
				enemyAttack(hpUser) calls enemyAttack funct, updates hpUser
			} if(both are alive) {
				_getch() to pause screen
				call ClearScreen() from .h to clear screen
			} else(someone is defeated) {
				if(user is defeated, hpUser below or = 0,  hpEnemy above 0) {
					print fail message...
					_getch(), DO NOT CLEAR SCREEN. GAVE OVER message displayed when main while loop ends
				} else { // enemy is defeated
					print congrats message...
					_getch()
				}
			}
		} if(menuChoice == 2, user heals) {
			heal(hpUser) hpUser updated
			enemyAttackorHeal - holds random number 1-10 to determine whether the enemy will attack or heal as well
			if (greater than or equal to 5) {
				enemyAttack(hpUser)		// attack the user
			} else if (less than 5) {
				enemyHeal(hpEnemy)		// enemy heals
			}
			_getch()
			ClearScreen() call
		}
		FOR WHEN MAIN WHILE LOOP ENDS (GAME IS OVER...)
		endl for extra space...
		display GAME OVER message

		// EXIT TO OS
		_getch()
		return 0
	*/
}

/* FUNCTION DEFINTIONS
void attack(int& hpEnemy) { for menuChoice = 1
	LOCAL VARS
	int attackRand - to hold rand number from 1-100 (for percentage chance, declared and initialized)
	int attackValRand - to hold rand number from 1-10 (for attack dmg, declared)

	if(attack is above 80 from attackRand, 20% chance it misses is true) {
		print you ATTACK and miss message...
		hpEnemy = hpEnemy - 0, nothing happens
	} else (attack lands, no arguments) {
		reset attackRand
		initialize attackValRand

		if(attackRand below 80, normal attack) { 
			print it was a normal attack and by how much...
			hpEnemy = hpEnemy - attackValRand
		} else (attackRand above 80 (20%), critical attack) {
			attackValRand = (int)((attackValRand * 2.5) + 5); calculations given by project guidelines
			print that critical hit was landed and for what value...
			hpEnemy = hpEnemy - attackValRand
		}
	}
}

void enemyAttack(int& hpUser) { happens if menuChoice = 1 & menuChoice = 2 
	LOCAL VARS
	int enemyAttackValRand; declaring var to hold rand dmg amount 1-10
	int enemyAttackRand = generateRandomValue(1, 100); rand number 1-100 for 20% chance attack misses

	if(enemyAttackRand > 80 (20% chance it misses) {
		print enemy ATTACKS and misses...
		hpUser = hpUser - 0, nothing happens
	} else (attack hits, no arguments) {
		enemyAttackValRand = generateRandomValue(1, 10), initializing enemyAttackValRand (attack dmg from 1-10)
		print val enemy attacks by...
		hpUser = hpUser - enemyAttackValRand
	}
}

void heal(int& hpUser) { for menuChoice = 2 
	// LOCAL VARS
	int healVal = generateRandomValue(3, 25), holds rand amount that user can heal from 3-25

	print amount hpUser healed from
	hpUser = hpUser + healVal
} 

void enemyhel(hpEnemy) { only possible when menuChoice = 2
	// built exactly as above... replace hpUser with hpEnemy
}
*/