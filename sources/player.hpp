#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "card.hpp"

namespace ariel
{
    class Player
    {
        private:
            std::string name;
            std::vector<Card> m_stack;
            std::vector<Card> m_taken;
            
        public:
            Player(std::string name);
            int stacksize() const;
            int cardesTaken() const;
            void takeCard(Card& c);
            void returnCard(Card& c);
    };
}

#endif /* PLAYER_H */
