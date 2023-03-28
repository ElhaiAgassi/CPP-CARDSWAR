// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// #include <algorithm>
// #include <random>
// #include <chrono>
// #include "game.hpp"
// using namespace std;
// using namespace ariel;

// Game::Game(Player& p1, Player& p2) : m_p1(p1), m_p2(p2), m_winner(nullptr), m_turn(&p1), m_turnNum(0)
// {
//     // Create the deck of cards
//     for (int value = 2; value <= 14; ++value) {
//         for (const auto& suit : {"Clubs", "Diamonds", "Hearts", "Spades"}) {
//             std::string rank;
//             if (value == 11) rank = "Jack";
//             else if (value == 12) rank = "Queen";
//             else if (value == 13) rank = "King";
//             else if (value == 14) rank = "Ace";
//             else rank = std::to_string(value);
//             m_deck.emplace_back(suit, rank, value);
//         }
//     }
//     // Shuffle the deck
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
// }

// void Game::playTurn()
// {
//     // If the game is already over, do nothing
//     if (m_winner != nullptr) return;

//     // Draw a card for each player
//     Card c1 = m_p1.drawCard(m_deck);
//     Card c2 = m_p2.drawCard(m_deck);

//     // Record the cards in the log
//     m_log.push_back(c1);
//     m_log.push_back(c2);

//     // Print the cards for this turn
//     cout << m_turn->getName() << " plays " << c1.getSuit() << " " << c1.getRank() << " (Value: " << c1.getValue() << ")" << endl;
//     cout << (m_turn == &m_p1 ? m_p2.getName() : m_p1.getName()) << " plays " << c2.getSuit() << " " << c2.getRank() << " (Value: " << c2.getValue() << ")" << endl;

//     // Determine the winner of the turn
//     if (c1 < c2) {
//         m_turn->addCardsToStack({c1, c2});
//         cout << m_turn->getName() << " wins this turn." << endl;
//     }
//     else if (c2 < c1) {
//         (m_turn == &m_p1 ? m_p2 : m_p1).addCardsToStack({c1, c2});
//         cout << (m_turn == &m_p1 ?

#include "game.hpp"
#include <iostream>

namespace ariel {
    Game::Game(Player& p1, Player& p2) : m_p1(p1), m_p2(p2) {}

    void Game::playTurn() {
        // TODO: Implement game logic for a single turn
    }

    void Game::playAll() {
        // TODO: Implement game logic for playing all turns until a player wins
    }

    void Game::printWiner() const {
        // TODO: Implement function to print the winner of the game
    }

    void Game::printLog() const {
        // TODO: Implement function to print the game log
    }

    void Game::printLastTurn() const {
        // TODO: Implement function to print the last turn of the game
    }

    void Game::printStats() const {
        // TODO: Implement function to print the game statistics
    }

    void Game::printPlayerStats() const {
        // TODO: Implement function to print the player statistics
    }
}
