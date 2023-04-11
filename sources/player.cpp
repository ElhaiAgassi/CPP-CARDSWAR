#include <iostream>
#include "player.hpp"

using namespace std;

Player::Player(const string &name) : _name(name), m_stack(), m_taken() {}

string Player::getName() const
{
    return this->_name;
}

Card Player::playCard()
{
    if (!m_stack.empty())
    {
        Card topCard = m_stack.back();
        m_playedCards.push_back(topCard);
        m_stack.pop_back();
        return topCard;
    }
    else
        throw std::runtime_error("No cards left to play");
}

void Player::takeCard(Card &c)
{
    m_stack.push_back(c);
}

void Player::getAllTheJackpot(std::vector<Card> *tempDeck)
{
    for (const Card &card : *tempDeck)
    {
        m_taken.push_back(card);
    }
}

void Player::winCard(Card &card)
{
    m_taken.push_back(card);
}

int Player::stacksize() const
{
    return m_stack.size();
}

int Player::cardesTaken() const
{
    return m_taken.size();
}

const Card &Player::getLastPlayedCard() const
{
    return m_playedCards.back();
}

int Player::getNumOfPlayedCards() const
{
    return m_playedCards.size();
}

const std::vector<Card> &Player::getPlayedCards() const
{
    return m_playedCards;
}

bool Player::operator==(const Player &other) const
{
    // Compare member variables for equality
    return (_name == other.getName());
}
