# COMP2113 Group Project 
Groupmates:
CHOW Yee Tak, Edwin (3035801611)
POON Ho Ting, Rain (3035800904)

## Education Purpose 

We believe that Mathematics and Logic is vital for everyone. The program training the logical thinking of the players while playing the games. With games such as guess the number, which involves a lot of mathematics and probability theories inside. For pacman, the player has to move to minimise the possiblity to getting caught by the bots. For maze, the player has to formulate a path while playing. These all trains the logical mind of the players. The plots are also added to the game so as to make the game more interesting. 

## How to play the game

Clone the game to your local directory. 

In the parent directory, type "make main". 

If error prompts out, create a bin directory by "mkdir bin" and type "make main" again.

Then, navigate to the bin folder with "cd bin" and run the game with "./main".

## System requirements

The programme runs on only Linux-based systems. 
Please ensure that your terminal window is at least 80x24 while running the game. 

## Core dependencies 

This programme is directed to be run on C++11. Please ensure that your Linux device has C++11 installed with a non-standard library unistd.h.
Please also ensure that the text files under ./dialogues are all available and non-altered.
Also, ./bin should also be present. 

# Project Description 
This is a game with a storyline. The game will also include minigames such as maze, pacman, peaceful war, etc.

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

Type the number and press enter to play the game. 

#### Game -- Peaceful War 

The player is required to play against the computer player. During the game, the player will first have one defence wall and 4 bases (A, B, C, D). The player will play Rock Paper Scissors with the computer. The winner can choose to build a defence wall or an attacker. If the winner has an attacker, the winner can choose to attack the opponent. The player who destroys all the 4 bases of the enemy wins.

Type your choice and press enter each time. If you don't see you win state for you to choose to build a defence wall or add an attacker, that means you lose that round. 

### Second Planet -- The World of Bots

In this planet, it seems that the civilisation here has experienced some disasters. All the buildings are torn down, and there are just some bots wandering. You discover that the power dusts are scattered around the ground.

#### Game -- Pacman

The player is required to get two scores without being caught by the bots.

Press WASD to navigate though the plane. B refers to the bots and P refers to yourself, S refers to the scores you have to reach to get the marks. 

You cannot touch the B with P and you have to eat all the S to win. 

### Third Planet -- The World of Mist (Maze)

On this planet, the ground is always covered with mist. Even using the most advanced satellite, the Stellians cannot observe the activities of the indigenous people very clearly. Some stellians decide to land and discover the mysterious world. Once they have landed, they find that they are trapped in a maze. Unfortunately, the fuel runs out. The magnetic field causes their equipment to break down. They have to escape the maze to recover the signals.

#### Game -- Maze

The player is required to finish the maze to get the power dusts.

The player can move with WASD. P refers to the player and D refers to the destination.
The player has to reach the destination. 

Interesting feature: the maze generation is printed while generation. The time between each iteration can also be increased to make the generation process more viewable. The size of the maze can also be changed. All the mentioned changes can be changed in maze.h. 

## Code Requirements

### Generation of random game sets or events

In every game, the gaming situation is given randomly. In Morra, how many hands the bot opens will be randomly generated by the code. In Typing Fast, the word shown will be chosen from a list of predetermined words randomly. In Guess The Number, the number to be guessed will be generated randomly. In Peaceful War, the choice of the bot on paper, scissor or stone will be random. In Pacman, the locations of bots are generated randomly. In Maze, the maze is generated by the algorithm (Randomized Depth-First Search) randomly.

Depth-First Search Algorithm: For generating the maze. 

### Data structures for storing game status

Overall: Player with name, number of power dusts, planet, and init function for the first 3 variables.

Guess The Number: int (the number)

Peaceful War: Self-defined data type (storing the number of bases, defenses, attackers, etc)

Pacman: int (x and y-coordinates), struct (player coordinates and score), 2d array (the map)

Maze: vector of vector of booleans (two dimensional vector), and rows consisting horizontal rows and vertical roles, random device mt19937_64 as included in the random library, as well as other fundamental data types such as int, etc.


### Dynamic memory management

Pointers: Passing arrays and values of player objects and files, as well as declaring our game classes as pointer variables to manage the memory dynamically. 

We used Standard Template Libraries (STLs) such as stack and vectors.

### File input/output (e.g., for loading/saving game status)

User data are stored in ./data/userdata.txt. 
Moreover, some logs are also outputted in ./logs/log.txt. 
Dialogues are stored in ./dialogues folder. 

### Program codes in multiple files

Codes are stored in multiple files, each with a .cpp and .h file (except main.cpp). They are compiled with the makefile. 

The code of each planet is stored in separate files. Once the player proceeds to the next stage, the main cpp file will call the corresponding function from another cpp file.

### Non-standard library used

unistd.h