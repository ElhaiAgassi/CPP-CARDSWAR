#pragma once

#include <vector>
#include <string>
#include "card.hpp"

    class Player
    {
    private:
        std::string _name;
        std::vector<Card> m_stack;
        std::vector<Card> m_taken;
        std::vector<Card> m_playedCards;

    public:
        Player(const std::string& name);
        std::string getName() const;
        Card playCard();
        void takeCard(Card& c);
        void returnCard(Card& c);
        int stacksize() const;
        int cardesTaken() const;
        const Card& getLastPlayedCard() const;
        int getNumOfPlayedCards() const;
        const std::vector<Card>& getPlayedCards() const;
    };


