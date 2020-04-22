#include <bits/stdc++.h>
#include "../headers/Game.h"


long get_rand(long lo, long hi) { // Used to generate random number (replaces the rand() function because this one works with dictionaries that have large number of words)
    auto moment = std::chrono::steady_clock::now().time_since_epoch().count();
    long num = moment % (hi - lo + 1);
    return num + lo;
}


Game::Game(std::string dictionary_name) {
    std::cout << "Starting a new game with file: \"" << dictionary_name << "\"!\n";
    dictionary_name = "dictionary/" + dictionary_name;
    std::fstream dict;
    std::string word;
    dict.open(dictionary_name, std::ios::in);
    if (!dict.good()) { // exit in case of errors while opening the dictionary file
        std::cerr << "Cannot open file!\n";
        exit(-1);
    }
    while(!dict.eof()) {
        dict >> word;
        loaded_words.push_back(word);
    }
    std::cout << "Added " << loaded_words.size() << " words from the dictionary!\n\n";
    dict.close();
}

void Game::start_new_game() {
    long number_of_words = loaded_words.size();
    long random_word_index = get_rand(0, number_of_words - 1); // get the index between 0 and the number of loaded words
    selected_word = loaded_words[random_word_index];
    selected_word_info = std::vector<bool>(selected_word.size());
    for(int i = 0; i < selected_word.size(); ++i) selected_word_info[i] = false;
    number_tries = get_rand(selected_word.size(), selected_word.size() * 2); // the number of tries should fall in [| length of the word, 2 x length of the word |]
    std::cout << "Game started! Initial number of tries: " << number_tries << "\n\n";
}

bool Game::check_game_over() {
    bool some_not_guessed = false;
    for(int i = 0; i < selected_word.size(); ++i) {
        if(!selected_word_info[i]) {
            some_not_guessed = true;
            break;
        }
    }
    if(!some_not_guessed) {
        std::cout << "You won! The word is: " << selected_word << "!\n\n";
        return true;
    } else if(number_tries == 0) {
        std::cout << "You lost! The word is: " << selected_word << "!\n\n";
        return true;
    }
    return false;
}

void Game::guess_character() {
    char typed_character;
    std::cout << "Hidden word is: ";
    for(int i = 0; i < selected_word.size(); ++i)
        if(selected_word_info[i])
            std::cout << selected_word[i];
        else 
            std::cout << '*';
    std::cout << '\n';
    std::cout << "Please type one character: ";
    std::cin >> typed_character;
    for(int i = 0; i < selected_word.size(); ++i)
        if(selected_word[i] == typed_character && !selected_word_info[i]) {
            selected_word_info[i] = true;
            std::cout << "The character was guessed correctly!\nRemaining number of tries is: " << number_tries << "\n\n";
            return;   
        }
    number_tries--;
    std::cout << "The character was not found!\nRemaining number of tries is: " << number_tries << "\n\n";
}