# CPP-CARDSWAR
#Card Game Project
This is a card game project written in C++, implemented using classes and objects. The project consists of several classes, including Card, Deck, Player, and Game, which work together to create a simple card game.

##Classes
###Card
The Card class represents a playing card, with properties such as value, suit, and name. It has methods to get and set these properties, as well as print the card information.

###Deck
The Deck class represents a deck of playing cards, implemented as a vector of Card objects. It has methods to shuffle the deck, deal cards, and get the current state of the deck.

###Player
The Player class represents a player in the card game. It has properties such as the player's name, hand of cards, and taken cards. It has methods to play a card, take cards from the pot, and get information about the player's hand and taken cards.

###Game
The Game class represents the card game itself. It takes two Player objects as input and manages the flow of the game, including dealing cards, playing rounds, and determining the winner.

##Usage
To use this card game project, you can create an instance of the Game class, passing in two Player objects as arguments. The Game class will then manage the flow of the game, including shuffling the deck, dealing cards to the players, and determining the winner based on the rules of the game.

You can customize the game by modifying the Player and Deck classes to implement different game rules or player behaviors. You can also extend the project by adding additional features, such as input/output for player actions, graphical user interface, or networking capabilities.

#### use the `make` orders in the MakeFile to compile all easyly
