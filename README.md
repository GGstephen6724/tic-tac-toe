# Tic Tac Toe (C++ Console Game)

A simple and interactive Tic Tac Toe game built in C++ for the console. This game allows a human player to compete against a basic CPU opponent. Includes suspenseful gameplay elements like timed pauses and real-time text effects to enhance the user experience.

## Features

- Play against a computer opponent
- Smooth console interaction with user prompts
- Suspenseful delays using `std::this_thread::sleep_for` for a more engaging experience
- Clear outcome messages (win/lose/tie)
- Option to quit anytime
- Score tracking

## Technologies Used

- C++
- Standard Library (`<iostream>`, `<cstdlib>`, `<ctime>`, `<thread>`, `<chrono>`)

## How to Run

1. Clone or download this repository.
2. Compile the code using a C++ compiler like `g++`:

```bash
g++ -o tictactoe main.cpp
```

## Run the executable:

Copy
Edit
```bash
./tictactoe
```

Windows users should run tictactoe.exe instead of ./tictactoe.

## How It Works
The player chooses a move (1–3 for Rock, Paper, or Scissors)

The computer randomly selects its move

The game checks for a winner after each round

Scores are tracked for both the player and the CPU

The game loops until the user chooses to quit

## Learning Objectives
This project helped reinforce the following C++ concepts:

Control structures (loops, conditionals)

Functions and modular code

Input/output with the console

Random number generation

Delays and timing with threads

Game logic and state tracking

## Future Improvements
Add a smarter AI that makes more strategic decisions

Allow for 2-player local mode

Add session history or a scoreboard across games
