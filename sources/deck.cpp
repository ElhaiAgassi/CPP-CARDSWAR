#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "deck.hpp"
#include <string>

using namespace std;

Deck::Deck()
{
    // Initialize the deck with 52 cards
    int value = 2;
    const string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    const string names[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    for (const auto &suit : suits)
    {
        for (const auto &name : names)
        {
            Card card(value, suit, name);
            m_deck.push_back(card);
        }
        value++;
    }

    // Shuffle the deck
    shuffle();
}

void Deck::shuffle()
{
    // // Fisher-Yates shuffle algorithm
    // int n = m_deck.size();

    // for (int i = n - 1; i > 0; i--)
    // {
    //     int j = rand() % (i + 1);
    //     swap(m_deck[i], m_deck[j]);
    // }
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

// void shuffle()
// {
//     // Shuffle the deck using Fisher-Yates shuffle algorithm
//     std::random_device rd;
//     std::mt19937 rng(rd());
//     std::shuffle(m_cards.begin(), m_cards.end(), rng);
// }

vector<Card> Deck::getDeck() const
{
    return this->m_deck;
}


// // test1
// int main()
// {
//     Deck* d = new Deck();
//     auto d = d.getDeck();
//     for (int i = d.size(); i >=0; --i)
//     {
//         Card c = d.drawCard();
//         cout << c.getName() << " of " << c. getSuit() << "val: " << static_cast<int>(i->getValue()) << endl;
//     }
// }