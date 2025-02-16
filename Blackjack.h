#pragma once
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"
#include <vector>
#include <map>

int calculateHandValue(const std::vector<Card>& hand, const std::map<int, int>& aceChoices);
void printHand(const std::vector<Card>& hand);
void playerTurn(std::vector<Card>& deck, std::vector<Card>& playerHand);
void dealerTurn(std::vector<Card>& deck, std::vector<Card>& dealerHand);
int playBlackjack(std::vector<Card> deck, std::vector<Card>& playerHand, std::vector<Card>& dealerHand);

#endif
