#include <string>
#include "card.hpp"
using namespace std;
namespace ariel{



Card::Card(int value, const std::string& suit, const std::string& name)
    : m_value(value), m_suit(suit), m_name(name)
{
}


string Card::getSuit() const {
    return m_suit;
}

string Card::getName() const {
    return m_name;
}

int Card::getValue() const {
    return m_value;
}



}