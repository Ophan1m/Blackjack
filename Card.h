#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <string>

enum ESuit
{
    HEARTS = 0,
    DIAMONDS,
    CLUBS,
    SPADES,
    COUNT
};
enum ENumber
{
    KING,
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN
};

struct Card
{
    ESuit suit;
    ENumber number;

    std::string getCardString() const;
    int getCardValue() const;
};

std::vector<Card> CreateDeck();
Card Draw(std::vector<Card>& deck);

#endif