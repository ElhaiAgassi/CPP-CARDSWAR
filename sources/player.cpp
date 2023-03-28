#include <iostream>
#include "player.hpp"

namespace ariel
{
    Player::Player(std::string name) : name(name), m_stack(), m_taken() {}

    int Player::stacksize() const
    {
        return m_stack.size();
    }

    int Player::cardesTaken() const
    {
        return m_taken.size();
    }

    void Player::takeCard(Card& c)
    {
        m_taken.push_back(c);
    }

    void Player::returnCard(Card& c)
    {
        m_stack.push_back(c);
    }
}
