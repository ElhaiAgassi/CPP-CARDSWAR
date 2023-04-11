#include "game.hpp"
#include "deck.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

Game::Game(Player &p1, Player &p2) : m_p1(p1), m_p2(p2)
{
    Deck m_deck; // Create a Deck object
    m_deck.splitDeck(&p1, &p2);
    Draws = 0;
    m_p1.setWin(0);
    m_p2.setWin(0);
}

void Game::playTurn()
{
    if (m_p1 == m_p2)
    {
        throw std::runtime_error("Error: Players cannot be the same.");
    }

    // if (m_p1.stacksize() <= 0 || m_p2.stacksize() <= 0)
    // {
    //     throw std::runtime_error("The players stack is out");
    // }

    // Both players put a card on the table
    Card c1 = m_p1.playCard();
    Card c2 = m_p2.playCard();

    vector<Card> temp_deck;
    temp_deck.push_back(c1);
    temp_deck.push_back(c2);

    cout << m_p1.getName() << " played " << c1.getName() << " of " << c1.getSuit() << ". ";
    cout << m_p2.getName() << " played " << c2.getName() << " of " << c2.getSuit() << ". ";

    // Compare the card values

    while (c1.getValue() == c2.getValue())
    {
        this->addDraw();
        cout << endl<< "Draw." << endl;
        if (m_p1.stacksize() <= 1 || m_p2.stacksize() <= 1)
        {

            cout << "Not enough cards for war." << endl
                 << "Spliting equaly the left cards" << endl;

            cout << "Bob stack size: " << m_p1.stacksize() << ". Alice stack size: " << m_p2.stacksize() << endl;
            while (m_p1.stacksize() > 0)
            {
                temp_deck.push_back(m_p1.playCard());
            }
            while (m_p2.stacksize() > 0)
            {
                temp_deck.push_back(m_p2.playCard());
            }

            for (const Card &card : temp_deck)
            {
                std::cout << "Value: " << card.getValue() << ", Suit: " << card.getSuit() << ", Name: " << card.getName() << std::endl;
            }

            for (size_t i = 0; i < temp_deck.size(); ++i) // split the cards
            {
                if (i % 2 == 0)
                {
                    m_p1.winCard(temp_deck.back());
                    temp_deck.pop_back();
                }
                else
                {
                    m_p2.winCard(temp_deck.back());
                    temp_deck.pop_back();
                }
            }
            break;
        }
        else
        {
            Card c3 = m_p1.playCard();
            temp_deck.push_back(c3);
            Card c4 = m_p2.playCard();
            temp_deck.push_back(c4);
            cout << m_p1.getName() << " played " << c3.getName() << " of " << c3.getSuit() << "(coverd). ";
            cout << m_p2.getName() << " played " << c4.getName() << " of " << c4.getSuit() << "(coverd). ";
            Card c5 = m_p1.playCard();
            temp_deck.push_back(c5);
            Card c6 = m_p2.playCard();
            temp_deck.push_back(c6);

            c1 = c5;
            c2 = c6;

            cout << m_p1.getName() << " played " << c1.getName() << " of " << c1.getSuit() << ". ";
            cout << m_p2.getName() << " played " << c2.getName() << " of " << c2.getSuit() << ". ";
        }
    }
    if (!temp_deck.empty()) // for case all finished after a long draw 
    {

        if (c1.getValue() < c2.getValue())
        {
            cout << m_p2.getName() << " wins." << endl;
            m_p2.getAllTheJackpot(&temp_deck);
            m_p2.setWin(m_p2.getWins()+1);
        }
        else
        {
            cout << m_p1.getName() << " wins." << endl;
            m_p1.getAllTheJackpot(&temp_deck);
            m_p1.setWin(m_p2.getWins()+1);

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

void Game::addDraw(){
    Draws++;
};


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
        cout << c.getName() << " of " << c.getSuit() << ", ";
    }
    cout << endl;

    cout << m_p2.getName() << " played: ";
    for (const Card &c : m_p2.getPlayedCards())
    {
        cout << c.getName() << " of " << c.getSuit() << ", ";
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
    printWiner();
    cout << endl;


    // Calculate and print win rate

        double winRateP1 = (static_cast<double>(m_p1.getWins())) * 100;
        double winRateP2 = (static_cast<double>(m_p2.getWins())) * 100;
        cout << "Player 1 Win Rate: " << winRateP1 << "%" << endl;
        cout << "Player 2 Win Rate: " << winRateP2 << "%" << endl;
    

    // Print cards won by each player
    cout << "Cards won by Player 1: " << m_p1.cardesTaken() << endl;
    cout << "Cards won by Player 2: " << m_p2.cardesTaken() << endl;

    // Calculate and print draw rate
    int totalDraws = this->Draws;
    if (totalDraws > 0)
    {
        double drawRate = (static_cast<double>(totalDraws) / (m_p1.getWins() + m_p2.getWins())) * 100;
        cout << "Draw Rate: " << drawRate << "%" << endl;
    }

    // Print amount of draws
    cout << "Total draws: " << totalDraws << endl;
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
