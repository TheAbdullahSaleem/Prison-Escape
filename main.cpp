#include <random>
#include <iostream>
int start() {
    int guess;
    std::cout << "Welcome to Prison Escape"  <<  "\n";
    std::cout << "There are five levels of this game"  <<  "\n";
    std::cout << "You will discover each level by passing from them"  <<  "\n";
    std::cout << "If you want to start the game press 1:  ";
    std::cin  >> guess;    
    while (guess != 1)
    {
        std::cout << "\n Seems like you entered something else then 1"  <<  "\n";
        std::cout << "If you want to start the game enter 1:  ";
        std::cin  >> guess;
    }

    return 0;
}
int level_1(){
    int guess;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,9);
    int secret = dis(gen);

    std::cout << "Welcome to Level 1"  <<  "\n";
    std::cout << "IN this level you need to guess the passcode for this door to open"  <<  "\n";
    std::cout << "This door leads you to next level. You will have three tries for the"  <<  "\n";
    std::cout << "guess \n Hints: The passcode is 1 digit long" << "\n";
    std::cout << "good luck!" << "\n";

    for ( int tries = 2;tries >= 0; --tries ) {
        int attempts = 3-tries ;
        std::cout << "Enter your guess:  ";
        std::cin  >> guess;
        if (guess == secret){
            std::cout << "You got that right in " << attempts << " Attempts \n ";
            break;
        } 
        else if ( guess > secret )
        {
            std::cout << "Get a little down \n ";
            std::cout << "Remaining Attempts : " << tries << "\n";
            if (tries == 0)
            {
                std::cout << "You lost it , try again \n ";
                std::cout << "The passcode was : " << secret;
                return 1;
            }
            
        }
        else
        {
            std::cout << "Get a little up \n ";
            std::cout << "Remaining Attempts : " << tries << "\n";
            if (tries == 0)
            {
                std::cout << "You lost it , try again \n ";
                std::cout << "The passcode was : " << secret;
                return 1;
            }
        }
    }
    return 0;
}
int level_2(){

}
int main() {
    start();
    level_1();
    return 0;
}