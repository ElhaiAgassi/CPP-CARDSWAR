#include "game.hpp"
#include <iostream>
#include <iomanip>

using namespace std; 

Game::Game(Player &p1, Player &p2) : m_p1(p1), m_p2(p2) {}

void Game::playTurn()
{
    // Both players put a card on the table
    Card c1 = m_p1.playCard();
    Card c2 = m_p2.playCard();

    cout << m_p1.getName() << " played " << c1.getName() << " of " << c1.getSuit() << ". ";
    cout << m_p2.getName() << " played " << c2.getName() << " of " << c2.getSuit() << ". ";

    // Compare the card values
    if (c1.getValue() > c2.getValue())
    {
        cout << m_p1.getName() << " wins." << endl;
        m_p1.takeCard(c1);
        m_p1.takeCard(c2);
    }
    else if (c1.getValue() < c2.getValue())
    {
        cout << m_p2.getName() << " wins." << endl;
        m_p2.takeCard(c1);
        m_p2.takeCard(c2);
    }
    else
    {
        cout << "Draw." << endl;
        m_p1.returnCard(c1);
        m_p2.returnCard(c2);

        // Put two more cards on the table
        Card c3 = m_p1.playCard();
        Card c4 = m_p2.playCard();

        cout << m_p1.getName() << " played " << c3.getName() << " of " << c3.getSuit() << ". ";
        cout << m_p2.getName() << " played " << c4.getName() << " of " << c4.getSuit() << ". ";

        // Compare the last card values
        if (c3.getValue() > c4.getValue())
        {
            cout << m_p1.getName() << " wins." << endl;
            m_p1.takeCard(c1);
            m_p1.takeCard(c2);
            m_p1.takeCard(c3);
            m_p1.takeCard(c4);
        }
        else if (c3.getValue() < c4.getValue())
        {
            cout << m_p2.getName() << " wins." << endl;
            m_p2.takeCard(c1);
            m_p2.takeCard(c2);
            m_p2.takeCard(c3);
            m_p2.takeCard(c4);
        }
        else
        {
            cout << "Draw." << endl;
            m_p1.returnCard(c1);
            m_p2.returnCard(c2);
            m_p1.returnCard(c3);
            m_p2.returnCard(c4);
        }
    }
}

void Game::playAll()
{
    // Play the game until one player runs out of cards
    while (m_p1.stacksize() > 0 && m_p2.stacksize() > 0)
    {
        playTurn();
    }
}

void Game::printWiner() const
{
    // Determine the winner based on the number of cards won
    if (m_p1.cardesTaken() > m_p2.cardesTaken())
    {
        cout << "Winner: " << m_p1.getName() << endl;
    }
    else if (m_p1.cardesTaken() < m_p2.cardesTaken())
    {
        cout << "Winner: " << m_p2.getName() << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
}

void Game ::printLog() const
{
    // Print the log of all cards played by both players
    cout << "Game Log: " << endl;
    cout << "----------" << endl;

    cout << m_p1.getName() << " played: ";
    for (const Card &c : m_p1.getPlayedCards())
    {
        cout << c.getName() << " of " << c.getSuit() << " ";
    }
    cout << endl;

    cout << m_p2.getName() << " played: ";
    for (const Card &c : m_p2.getPlayedCards())
    {
        cout << c.getName() << " of " << c.getSuit() << " ";
    }
    cout << endl;
}

void Game::printLastTurn() const
{
    // Print the cards played in the last turn
    cout << "Last Turn: " << endl;
    cout << "----------" << endl;
    cout << m_p1.getName() << " played: ";
    const Card &c1 = m_p1.getLastPlayedCard();
    cout << c1.getName() << " of " << c1.getSuit() << endl;

    cout << m_p2.getName() << " played: ";
    const Card &c2 = m_p2.getLastPlayedCard();
    cout << c2.getName() << " of " << c2.getSuit() << endl;
}

void Game::printStats() const
{
    // Print overall game statistics
    cout << "Game Statistics: " << endl;
    cout << "-----------------" << endl;
    cout << "Total cards played: " << m_p1.getNumOfPlayedCards() + m_p2.getNumOfPlayedCards() << endl;
    cout << "Total cards taken: " << m_p1.cardesTaken() + m_p2.cardesTaken() << endl;
    cout << "Winner: ";
    printWiner();
    cout << endl;
}

void Game::printPlayerStats() const
{
    // Print individual player statistics
    cout << "Player Statistics: " << endl;
    cout << "------------------" << endl;
    cout << m_p1.getName() << ": " << endl;
    cout << "Total cards played: " << m_p1.getNumOfPlayedCards() << endl;
    cout << "Total cards taken: " << m_p1.cardesTaken() << endl;

    cout << m_p2.getName() << ": " << endl;
    cout << "Total cards played: " << m_p2.getNumOfPlayedCards() << endl;
    cout << "Total cards taken: " << m_p2.cardesTaken() << endl;
}
