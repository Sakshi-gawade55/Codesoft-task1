#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <climits>  

int main() {
    std::srand(std::time(0));
    int secretNumber = std::rand() % 100 + 1; 
    int guess = 0;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (guess != secretNumber) {
        std::cout << "Make a guess: ";
        std::cin >> guess;

        
        if (!std::cin) {
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << "Please enter a valid integer." << std::endl;
            continue;
        }

        
        if (guess < secretNumber) {
            std::cout << "Too low. Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number!" << std::endl;
        }
    }

    return 0;
}
