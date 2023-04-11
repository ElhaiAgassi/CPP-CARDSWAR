#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "deck.hpp"
#include "player.hpp"

#include <string>

using namespace std;

Deck::Deck()
{
    // Initialize the deck with 52 cards
    int value = 2;
    const string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    const string names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    for (const auto &name : names)
    {
        for (const auto &suit : suits)
        {
            Card card(value, suit, name);
            m_deck.push_back(card);
          //  std::cout << "Value: " << value << ", Suit: " << suit << ", Name: " << name << std::endl;
        }
        value++;
    }

    // Shuffle the deck
    shuffle();
}

void Deck::shuffle()
{
    std::shuffle(m_deck.begin(), m_deck.end(), std::random_device());
}

Card Deck::drawCard()
{
    // Draw the top card from the deck
    Card card = m_deck.back();
    m_deck.pop_back();
    return card;
}

bool Deck::isEmpty() const
{
    // Check if the deck is empty
    return m_deck.empty();
}

int Deck::size() const
{
    // Get the size of the deck
    return m_deck.size();
}

const vector<Card> *Deck::getDeck() const
{
    return &m_deck;
}

void Deck::splitDeck(Player *p1, Player *p2)
{
    for (size_t i = 0; i < m_deck.size(); ++i)
    {
        if (i % 2 == 0)
        {
            p1->takeCard(m_deck[i]);
        }
        else
        {
            p2->takeCard(m_deck[i]);
        }
    }
}
