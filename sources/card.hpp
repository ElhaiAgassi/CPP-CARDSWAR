#pragma once
#include <string>
namespace ariel
{

    class Card
    {
    private:
        int m_value;
        std::string m_suit;
        std::string m_name;

    public:
        Card(int value, const std::string &suit, const std::string &name);
        int getValue() const;
        std::string getSuit() const;
        std::string getName() const;
    };
}