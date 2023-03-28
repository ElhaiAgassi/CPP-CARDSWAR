#include <string>
#include "card.hpp"

namespace ariel {

    Card::Card(std::string suit, std::string rank, int value)
        : suit(suit), rank(rank), value(value)
    {
    }

    std::string Card::getSuit() const {
        return suit;
    }

    std::string Card::getRank() const {
        return rank;
    }

    int Card::getValue() const {
        return value;
    }

    bool Card::operator<(const Card& other) const {
        return value < other.value;
    }

}
