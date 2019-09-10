/*
	animal.cpp

	author: Casey Turner
	date:   4/30/19

	Animal/20 questions program for CSCI 262.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "functions.h"

using namespace std;


int main() {
	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true) {
		string tmp;
		int choice;

		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());

		switch (choice) {
		case 1:
			//play_game(root);
			break;
		case 2:
			//save_game_tree(root);
			break;
		case 3:
			break;
		default:
			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	//delete_game_tree(root);
	return 0;
}
