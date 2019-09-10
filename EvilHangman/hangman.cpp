/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author: Casey Turner

    last modified: 3/14/19
*/

#include "hangman.h"
using namespace std;

// constructor
hangman::hangman() { 
    ifstream dict;
    dict.open("dictionary.txt");
    if(dict.is_open()){
        string tempWord;
        while(!dict.eof()){
            dict >> tempWord;
            _words.emplace(tempWord);

        }
    }
    else{
        cerr << "error opening file" << endl;
    }
    dict.close();
}


// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int numGuesses, bool showWords, int length) {
     _length = length;
    _showWords = showWords;
     _numGuesses = numGuesses;
    _charsGuessed = "";
     for(int i = 0; i < length; i++) {
         _hiddenWord+="-";
     }

    string temp;
    for (auto entry: _words) {
        _words.erase(temp);
        if(entry.length() != _length){
            temp = entry;
        }
    }
    _words.erase(temp);

}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
   map<string, set<string>> families;

    for (auto entry:_words){
        string key = "";
        for(char l:entry){
            if(l == c){
                key+=c;
            }
            else{
                key+='-';
            }
        }
        families[key].insert(entry);
    }

    int max = 0;
    string maxKey;
    for (auto family: families) {
        if(family.second.size() > max){
            max = family.second.size();
            maxKey = family.first;
        }
    }


    _words = families.at(maxKey);
    if(_showWords){
        cout << "The number of possible words remaining are: " << max << endl;
    }
    for(int i = 0; i < _hiddenWord.length();i++){
        if(maxKey.at(i) != '-'){
            _hiddenWord.replace(i,1,1,c);
        }
    }

    if(maxKey.find(c) == -1){
        _numGuesses--;
        if(_charsGuessed.length() == 0){
            _charsGuessed+=c;
        }
        else {
           int length =  _charsGuessed.length();
            for (int i = 0; i < length; i++) {
                if (c <= _charsGuessed.at(i)) {
                    _charsGuessed.insert(i, 1, c);
                    break;
                } else if(i == length-1){
                    _charsGuessed+=c;
                }
            }
        }
        return false;
    }
    return true;
}


// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return _hiddenWord;
}


// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return _numGuesses;
}


// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    return _charsGuessed;
}


// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    if(_charsGuessed.find(c) != -1){
        return true;
    }
    return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    if (_words.size() > 1){
        return false;
    }
    if(_hiddenWord.find('-') != -1){
        return false;
    }
    return true;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    if(_numGuesses <= 0){
        return true;
    }
    return false;
}


// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    return *_words.begin();
}


