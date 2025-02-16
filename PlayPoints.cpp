#include "PlayPoints.h"
#include <iostream>

void playPoints(int totalCash) {
    int playerCash = 500;
    int dealerCash = 500;

    while (playerCash < totalCash && dealerCash < totalCash) {
        std::vector<Card> deck = CreateDeck();
        std::vector<Card> playerHand;
        std::vector<Card> dealerHand;

        int result = playBlackjack(deck, playerHand, dealerHand);

        if (result == 1) {
            playerCash += 100;
            dealerCash -= 100;
        }
        else if (result == -1) {
            playerCash -= 100;
            dealerCash += 100;
        }

        std::cout << "\nYour current pool is: " << playerCash << "$" << std::endl;
        std::cout << "The dealer's current pool is: " << dealerCash << "$" << std::endl;

        std::cout << "\nContinue to the next round!\n" << std::endl;
        std::cin.ignore();  // Wait for user input
    }

    if (playerCash >= totalCash) {
        std::cout << "\n---You win! Take your money and run!---" << std::endl;
    }
    else if (dealerCash >= totalCash) {
        std::cout << "\n---You lose! Take your dignity and run!---" << std::endl;
    }
}
