# COMP2113 Group Project 
Groupmates:
CHOW Yee Tak, Edwin
POON Ho Ting, Rain 

# How to play the game

In the parent directory, type make main
then, navigate to the bin folder with "cd ./bin" and run the game with ./main

# System requirements

The programme runs on only Linux-based systems. Please ensure that your terminal window is at least 80x24 while running the game. 

# Project Description 
This is a game with a storyline. The game will also include minigames such as maze, snake, peaceful war, etc.

## Background
The Stellians is a high-level civilization which has the ability to manipulate a galaxy. They have recently started an exploration journey aiming at collecting power dusts, which serves as the energy to power their civilization. 
As such, they go to 6 different planets and explore. Meanwhile, they will encounter the indigenous persons of the planet. They might fight, deal, or settle with them to gain the power dust while playing games with them. After finishing playing on a planet, they will choose to destroy the planet to gain all the power dusts or just leave it and proceed to the next planet.

## Games 

Guess the number
Peaceful war
Pacman 
Maze

### First Planet -- The World of Mathematics

“Mathematics is the language in which God has written the universe.” -- Galileo Galilei. The indigenous people on this planet love mathematics very much, particularly probability theories. The player is required to play Guess The Number and Peaceful War on this planet. 

#### Game -- Guess The Number

The player is required to guess a number between 1 and 100. The bound will be lowered or increased to the value the user inputs, if the user fails to get the correct number. The player wins if the player guesses the correct number. The fewer times the user uses to get the correct number, the more power dusts the player gets in that game. 

#### Game -- Peaceful War 

The player is required to play against the computer player. During the game, the player will first have one defence wall and 4 bases (A, B, C, D). The player will play Rock Paper Scissors with the computer. The winner can choose to build a defence wall or an attacker. If the winner has an attacker, the winner can choose to attack the opponent. The player who destroys all the 4 bases of the enemy wins.

### Second Planet -- The World of Bots

In this planet, it seems that the civilisation here has experienced some disasters. All the buildings are torn down, and there are just some bots wandering. You discover that the power dusts are scattered around the ground.

#### Game -- Pacman

The player is required to get two scores without being caught by the bots.

### Third Planet -- The World of Mist (Maze)

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

Guess The Number: int (the number)

Peaceful War: Self-defined data type (storing the number of bases, defenses, attackers, etc)

Pacman: int (x and y-coordinates), struct (player coordinates and score), 2d array (the map)

Maze: Two-dimensional arrays/(or with self-defined data type) (to store the maze), two int (store the position of the player)

Struct: A self-defined data structure storing the gameplay data.
For example, the player’s name, number of power dusts, current planet, etc. 

### Dynamic memory management

Pointers: Passing arrays and values of power dusts. Pointers might be also used for some advanced data structures.

We used Standard Template Libraries (STLs) such as stack and vectors, as well as declaring our game classes as pointer variables to manage the memory dynamically. 

Array: add more elements to the array

### File input/output (e.g., for loading/saving game status)

User data are stored in ./data/userdata.txt. Moreover, some logs are also output in ./logs/log.txt. Dialogues are stored in ./dialogues folder. 

For saving game status, config files, etc.

### Program codes in multiple files

Codes are stored in multiple files, each with a .cpp and .h file (except main.cpp). They are compiled with the makefile. 

The code of each planet is stored in separate files. Once the player proceeds to the next stage, the main cpp file will call the corresponding function from another cpp file.