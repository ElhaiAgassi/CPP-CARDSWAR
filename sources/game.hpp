#pragma once

#include "player.hpp"
#include "deck.hpp"
namespace ariel{
    class Game {
    private:
        Player& m_p1;
        Player& m_p2;
        Deck m_deck; // Declaration of m_deck member variable
        int Draws;
        

    public:
        Game(Player& p1, Player& p2);
        void playTurn();
        void playAll();
        void printWiner() const;
        void printLog() const;
        void printLastTurn() const;
        void printStats() const;
        void printPlayerStats() const;
        void addDraw();
    };


}