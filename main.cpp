#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void countdown() {
    cout << "\n3...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    cout << "2...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    cout << "1...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    cout << "Game starts!\n\n";
}

void start() {
    string ready;
    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "Are you ready? (y/n): ";
    cin >> ready;

    if (ready == "n" || ready == "N") {
        cout << "Okay... I'll wait...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        start();
    } else {
        cout << "Let's go!";
        countdown();
    }
}

string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "ROCK";
        case 2: return "PAPER";
        case 3: return "SCISSORS";
        default: return "UNKNOWN";
    }
}

// Returns "win", "lose", or "tie"
string determineWinner(int player, int cpu) {
    if (player == cpu) return "tie";
    if ((player == 1 && cpu == 3) ||
        (player == 2 && cpu == 1) ||
        (player == 3 && cpu == 2)) {
        return "win";
    } else {
        return "lose";
    }
}

void suspensePrint(const string& text, int delay = 100) {
    for (char c : text) {
        cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    cout << "\n";
}

void gameLoop() {
    srand(static_cast<unsigned int>(time(0)));

    int playerScore = 0;
    int cpuScore = 0;

    while (true) {
        int player_choice;
        int cpu_choice = rand() % 3 + 1;

        cout << "Choose:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Or type 0 to quit.\n";
        cout << "> ";
        cin >> player_choice;

        if (player_choice == 0) {
            cout << "Final Score:\n";
            cout << "You: " << playerScore << " | CPU: " << cpuScore << "\n";
            cout << "Thanks for playing!\n";
            break;
        }

        if (player_choice < 1 || player_choice > 3) {
            cout << "Invalid choice. Try again.\n\n";
            continue;
        }

        string playerName = getChoiceName(player_choice);
        string cpuName = getChoiceName(cpu_choice);

        cout << "\nYou chose: " << playerName << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        suspensePrint("CPU is thinking...", 70);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        cout << "CPU chose: " << cpuName << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        string result = determineWinner(player_choice, cpu_choice);

        if (result == "win") {
            playerScore++;
            suspensePrint("You win this round!", 80);
        } else if (result == "lose") {
            cpuScore++;
            suspensePrint("CPU wins this round!", 80);
        } else {
            suspensePrint("It's a tie!", 80);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        cout << "Current Score - You: " << playerScore << " | CPU: " << cpuScore << "\n";
        cout << "\n--------------------------\n\n";
    }
}

int main() {
    start();
    gameLoop();
    return 0;
}
