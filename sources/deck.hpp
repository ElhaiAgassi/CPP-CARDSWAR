#pragma once
#include "card.hpp"
#include <vector>
#include "player.hpp"

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
    const std::vector<Card>* getDeck() const;

    //split the Deck to both players
    void splitDeck(Player* p1, Player* p2);

private:
    // Vector to store the deck of cards
    vector<Card> m_deck;
};
