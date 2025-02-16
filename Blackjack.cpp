#include "Blackjack.h"
#include <iostream>

int calculateHandValue(const std::vector<Card>& hand, const std::map<int, int>& aceChoices) {
    int totalValue = 0;
    for (size_t i = 0; i < hand.size(); ++i) {
        if (hand[i].number == ENumber::ACE && aceChoices.find(i) != aceChoices.end()) {
            totalValue += aceChoices.at(i);
        } else {
            totalValue += hand[i].getCardValue();
        }
    }
    return totalValue;
}

void printHand(const std::vector<Card>& hand) {
    for (const Card& card : hand) {
        std::cout << card.getCardString() << std::endl;
    }
}

void playerTurn(std::vector<Card>& deck, std::vector<Card>& playerHand) {
    std::string choice;
    std::map<int, int> aceChoices;

    while (true) {
        std::cout << "\nYour hand: " << std::endl;
        printHand(playerHand);

        for (size_t i = 0; i < playerHand.size(); ++i) {
            if (playerHand[i].number == ENumber::ACE && aceChoices.find(i) == aceChoices.end()) {
                int aceChoice;
                do {
                    std::cout << "\nYou have an Ace. Would you like it to be 1 or 11? ";
                    std::cin >> aceChoice;
                } while (aceChoice != 1 && aceChoice != 11);

                aceChoices[i] = aceChoice;
            }
        }

        int handValue = calculateHandValue(playerHand, aceChoices);
        std::cout << "\nTotal value: " << handValue << std::endl;

        if (handValue >= 21) break;

        std::cout << "Would you like to HIT or STAND? ";
        std::cin >> choice;

        if (choice == "HIT" || choice == "hit") {
            playerHand.push_back(Draw(deck));
        } else if (choice == "STAND" || choice == "stand") {
            break;
        } else {
            std::cout << "Invalid choice. Please enter HIT or STAND." << std::endl;
        }
    }
}

void dealerTurn(std::vector<Card>& deck, std::vector<Card>& dealerHand) {
    std::cout << "\nDealer's hand: " << std::endl;
    printHand(dealerHand);
    int dealerHandValue = calculateHandValue(dealerHand, {});

    while (dealerHandValue < 17) {
        dealerHand.push_back(Draw(deck));
        dealerHandValue = calculateHandValue(dealerHand, {});
    }

    std::cout << "\nFinal dealer value: " << dealerHandValue << std::endl;
}

int playBlackjack(std::vector<Card> deck, std::vector<Card>& playerHand, std::vector<Card>& dealerHand) {
    playerHand.push_back(Draw(deck));
    playerHand.push_back(Draw(deck));

    dealerHand.push_back(Draw(deck));
    dealerHand.push_back(Draw(deck));

    std::cout << "Dealer's hand: " << std::endl;
    std::cout << dealerHand[0].getCardString() << " and [Hidden Card]" << std::endl;

    playerTurn(deck, playerHand);
    dealerTurn(deck, dealerHand);

    int finalPlayerValue = calculateHandValue(playerHand, {});
    int finalDealerValue = calculateHandValue(dealerHand, {});

    if (finalPlayerValue > 21) return -1;
    if (finalDealerValue > 21) return 1;
    if (finalPlayerValue > finalDealerValue) return 1;
    if (finalPlayerValue < finalDealerValue) return -1;
    return 0;
}
