# COMP2113 Group Project 
Groupmates:
CHOW Yee Tak, Edwin
POON Ho Ting, Rain 

# Project Description 
This is a game with a storyline. The game will also include minigames such as maze, snake, peaceful war, etc.

## Background
The Stellians is a high-level civilization which has the ability to manipulate a galaxy. They have recently started an exploration journey aiming at collecting power dusts, which serves as the energy to power their civilization. 
As such, they go to 6 different planets and explore. Meanwhile, they will encounter the indigenous persons of the planet. They might fight, deal, or settle with them to gain the power dust while playing games with them. After finishing playing on a planet, they will choose to destroy the planet to gain all the power dusts or just leave it and proceed to the next planet.

## Games 

Snake 
Maze
Peaceful war
Morra
Typing Fast
Guess the number
Blackjack

### First Planet -- The World of Hands

People on this planet love playing with their hands so much, particularly fists and palms. To build relationships with the people, the Stellians have to play morra with them to win their respect.

#### Game -- Morra

You and another player take turns to shout zero, five, ten, fifteen or twenty. You two have to close or open your hands at every turn. If the number the player shouts out equals the sum of fingers, he/ she wins this turn. If he/ she wins two consecutive turns, the game is over. If what the player says does not match with the opened hands, it will be another player’s turn to say.

### Second Planet -- The World of Language

A medium-level civilization lives on this planet. Their civilization has started to develop quickly since they had the common language so they love language very much. The player is required to type words in a limited time to play on this planet. 

#### Game -- Typing Fast

The player needs to type the word, which is shown on the screen, within the time limit. After typing ten words before time is up, the player will win the game.

### Third Planet -- The World of Mathematics

“Mathematics is the language in which God has written the universe.” -- Galileo Galilei. The indigenous people on this planet love mathematics very much, particularly probability theories. The player is required to play Guess The Number and Peaceful War on this planet. 

#### Game -- Guess The Number

The player is required to guess a number between 1 and 100. The bound will be lowered or increased to the value the user inputs, if the user fails to get the correct number. The player wins if the player guesses the correct number. The fewer times the user uses to get the correct number, the more power dusts the player gets in that game. 

#### Game -- Peaceful War 

The player is required to play against the computer player. During the game, the player will first have one defence wall and 4 bases (A, B, C, D). The player will play Rock Paper Scissors with the computer. The winner can choose to build a defence wall or an attacker. If the winner has an attacker, the winner can choose to attack the opponent. The player who destroys all the 4 bases of the enemy wins.

### Fourth Planet -- The World of Snake

The snake is deemed as divine in this world, and all the locals worship the snake. To get the resources from the locals’ hands, the Stellians have to pretend to be the snake to steal energy.

#### Game -- Snake

The player needs to control the snake to eat ten dots. If the snake crashes with the boundary, the player will lose the game.

### Fifth Planet -- The World of Twenty-One

This planet is full of Twenty-Ones. Its day consists of 21 Hours (On the Galaxy Time basis) per day, 21 days per month and the people like 21 very much. Thus, the player is required to play Blackjack with them. 

#### Game -- Blackjack

The player is required to play a traditional poker game called Blackjack. The objective of this game is to get the sum of cards equal to or less than 21, with the disparity with 21 as small as possible. In this game, there will be two cards distributed to the player at the first time, and the player can choose to get the third card or not. After getting the third card, the player can choose to get the forth card or not. The logic continues for the fifth card. Once the sum of the cards exceeds 21, the player loses instantly. If the player does not lose after getting five cards, the player wins instantly. The closer the sum of the cards to 21 is, the more power dusts the player gets. 

### Sixth Planet -- The World of Mist (Maze)

On this planet, the ground is always covered with mist. Even using the most advanced satellite, the Stellians cannot observe the activities of the indigenous people very clearly. Some stellians decide to land and discover the mysterious world. Once they have landed, they find that they are trapped in a maze. Unfortunately, the fuel runs out. The magnetic field causes their equipment to break down. They have to escape the maze to recover the signals.

#### Game -- Maze

The player is required to finish the maze to get the power dusts. 

### Finals

Depending on the number of power dusts, the player will acquire a title.

Master of the Universe
Manipulator of the Galaxy 
The Wild Voyager 
Civilization Eliminator

## Code Requirements

### Generation of random game sets or events

In every game, the gaming situation is given randomly. In Morra, how many hands the bot opens will be randomly generated by the code. In Typing Fast, the word shown will be chosen from a list of predetermined words randomly. In Guess The Number, the number to be guessed will be generated randomly. In Peaceful War, the choice of the bot on paper, scissor or stone will be random. In Snake, the locations of dots are generated randomly. In Blackjack, the cards are distributed randomly to the player. In Maze, the maze is generated by the algorithm randomly.

Depth-First Search Algorithm: For generating the maze (External Libraries might be used, if available)

### Data structures for storing game status

Morra: int (the number of turns the game has progressed)

Typing Fast: string (storing the words), int (the time limit)

Peaceful War: Self-defined data type (storing the number of bases, defenses, attackers, etc)

Guess The Number: int (the number)

Snake: int (x and y-coordinates)

Blackjack: array (the cards held by the players)

Maze: Two-dimensional arrays/(or with self-defined data type) (to store the maze), two int (store the position of the player)

Struct: A self-defined data structure storing the gameplay data. 
For example, the player’s name, number of power dusts, current planet, etc. 

### Dynamic memory management

Pointers: Passing arrays and values of power dusts. Pointers might be also used for some advanced data structures.

Array: add more elements to the array

### File input/output (e.g., for loading/saving game status)

For saving game status, config files, etc.

### Program codes in multiple files

The code of each planet is stored in separate files. Once the player proceeds to the next stage, the main cpp file will call the corresponding function from another cpp file.
