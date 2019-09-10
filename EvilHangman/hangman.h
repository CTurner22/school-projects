#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: Casey Turner

    last modified: 3/14/19
*/

#include <string>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;
//template <int, class string> class map;
/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();

    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int numGuesses, bool showWords, int length);

    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);

    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
	int get_guesses_remaining();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();

private:
    set<string> _words;
    int _length;
    bool _showWords;
    int _numGuesses;
    string _charsGuessed;
    string _hiddenWord;

};

#endif
