
# WAR card game

In this task, we implement the WAR card game for two players. There is a standard deck of 52 cards, which is shuffled randomly at the beginning of the game and divided equally between the two players. In each turn, the players draw one card from the top of their pile, and the player with the highest card takes both cards. If the players draw two cards with equal value, they place one card face down and one card face up. The player with the highest face-up card takes all six cards. In case of another tie, they continue with a face-down card and a face-up card until one player wins. The game continues until one player takes the entire deck, or until the cards run out. If the cards run out during a tiebreaker, each player takes back their discarded cards and splits the remaining cards in the pot evenly. The game continues until both players run out of cards, and the winner is the player who takes the most cards.

To see examples of the class in action, refer to `Demo.cpp`.

## TDD
In the current step I implemented very basic skeleton of the game the tests. it made according the TDD approached.

TDD is a software development approach that involves writing automated tests before writing any actual code. The process typically involves the following steps:

Write a test: The developer writes a test that checks for a specific behavior or functionality.
Run the test: The test will fail initially since the functionality has not yet been implemented.
Write the code: The developer writes the minimum amount of code needed to pass the test.
Run the test again: If the test passes, the developer can move on to the next test. If it fails, the developer goes back and modifies the code until the test passes.
Refactor the code: Once the test passes, the developer can refactor the code to improve its quality and readability while ensuring that all the tests continue to pass.

@Elhai.Agassi
