#include <bits/stdc++.h>

#ifndef GAME_H
#define GAME_H

class Game {
private:
    std::string dictionary_name; // name of the dictionary file located in the "dictionary" folder
    std::vector<std::string> loaded_words; // list of words contained in the dictionary
    std::string selected_word; 
    std::vector<bool> selected_word_info;// information about the randomly selected word (whether each character has been guessed or not)
    int number_tries = 0; // current remaining number of tries in the game

public:    
    Game(std::string dictionary_name);
    void start_new_game();
    bool check_game_over();
    void guess_character();
};

#endif