#pragma once

#include "card.hpp"
#include <vector>

using namespace std;

class Deck
{
public:
    // Constructor
    Deck();

    // Shuffle the deck
    void shuffle();

    // Draw a card from the top of the deck
    Card drawCard();

    // Check if the deck is empty
    bool isEmpty() const;

    // Get the size of the deck
    int size() const;

     // Get the deck
    vector<Card> getDeck() const;

private:
    // Vector to store the deck of cards
    vector<Card> m_deck;
};
