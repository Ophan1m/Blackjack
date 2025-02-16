#include "Card.h"
#include <algorithm>
#include <random>

std::string Card::getCardString() const 
{
    static std::string suitNames[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    static std::string numberNames[] = { "King", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen" };
    return numberNames[static_cast<int>(number)] + " of " + suitNames[static_cast<int>(suit)];
}

int Card::getCardValue() const 
{
    switch (number) 
    {
    case ACE: 
    return 11;
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
    case SIX: 
    case SEVEN: 
    case EIGHT: 
    case NINE: 
    case TEN:
        return static_cast<int>(number);
    case JACK: 
    case QUEEN: 
    case KING: 
        return 10;
    default: 
        return 0;
    }
}

std::vector<Card> CreateDeck() 
{
    std::vector<Card> deck;
    for (int suit = 0; suit < ESuit::COUNT; ++suit) 
    {
        for (int number = ENumber::KING; number <= ENumber::QUEEN; ++number) 
        {
            deck.push_back(Card{ static_cast<ESuit>(suit), static_cast<ENumber>(number) });
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
    return deck;
}

Card Draw(std::vector<Card>& deck) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, deck.size() - 1);
    int index = dis(gen);
    Card card = deck[index];
    deck.erase(deck.begin() + index);
    return card;
}
