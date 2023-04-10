#pragma once

#include "player.hpp"

    class Game {
    private:
        Player& m_p1;
        Player& m_p2;
    public:
        Game(Player& p1, Player& p2);
        void playTurn();
        void playAll();
        void printWiner() const;
        void printLog() const;
        void printLastTurn() const;
        void printStats() const;
        void printPlayerStats() const;
    };


