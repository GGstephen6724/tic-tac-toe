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
