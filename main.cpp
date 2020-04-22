#include <bits/stdc++.h>
#include "headers/Game.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Please specify a dictionary name as the only argument!";
        exit(-1);
    }
    Game game(argv[1]);
    std::string restart_ans;
    while(true) {
        game.start_new_game();
        while(!game.check_game_over()) {
            game.guess_character();
        }
        std::cout << "Do you want to restart the Game: (if yes type 'yes', anything else if you wish to quit!): ";
        std::cin >> restart_ans;
        if(restart_ans != "yes") {
            std::cout << "\nThanks for playing!\n";
            break;
        } else 
            std::cout << '\n';
    }
    return 0;
}