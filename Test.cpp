#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("Test 1 - Initialization") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Test 2 - Play turn") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();
    
    CHECK(((p1.stacksize() == 25) || (p1.stacksize() == 23)));
    CHECK(((p2.stacksize() == 25) || (p2.stacksize() == 23)));

    
}

TEST_CASE("Test 3 - Play all turns") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playAll();

    CHECK((p1.stacksize() == 0  ||  p2.stacksize() == 0));
 
}

TEST_CASE("Test 4 - after 1 turn") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    CHECK((p1.stacksize() < 26  &&  p2.stacksize()  < 26));
 
}

TEST_CASE("Test 5 - after 1 round") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    CHECK((p1.cardesTaken() > 0  ||  p2.cardesTaken()  > 0));
 
}
TEST_CASE("Test 6 - Play a single turn")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playTurn();
    bool a = (p1.cardesTaken() == 2 || p1.cardesTaken() == 6);
    bool b = (p2.cardesTaken() == 2 || p2.cardesTaken() == 6);
    CHECK((a || b));

}

TEST_CASE("Test 7 - Play a full game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();

    CHECK((p1.cardesTaken() + p2.cardesTaken()) == 52);
    CHECK((p1.stacksize() == 0 || p2.stacksize() == 0));
}

TEST_CASE("Test 8 - ptint winner")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());   
}


TEST_CASE("Test 9 - Print log")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Test 10 - Print last turn")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("Test 11 - Print last turn") {
    Player p1("Alice"); 
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Test 12: cards status after a round") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    int prevCardsTaken2 = p2.cardesTaken();
    int prevCardsTaken1 = p1.cardesTaken();
    game.playTurn();
    int newCardsTaken2 = p2.cardesTaken();
    int newCardsTaken1 = p1.cardesTaken();
    CHECK((newCardsTaken2 > prevCardsTaken2 || newCardsTaken1 > prevCardsTaken1));
}

TEST_CASE("Test 13: print statistics") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printStats());
}

TEST_CASE("Test 14: play after finish") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();// Play all turns to finish the game
    CHECK_THROWS(game.playTurn());
}

 TEST_CASE("Test 5 - Constructor work"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game(p1,p1));
 }