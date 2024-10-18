#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to roll a die and return the result
int rollDie() {
    return rand() % 6 + 1; // Returns a number between 1 and 6
}

// Function for player's turn
int playerTurn() {
    int score = 0;
    char choice;

    do {
        int roll = rollDie();
        cout << "You rolled: " << roll << endl;

        if (roll == 1) {
            cout << "You rolled a 1! Your turn ends with 0 points.\n";
            return 0; // If a 1 is rolled, the player loses their turn and score
        }

        score += roll;
        cout << "Current score: " << score << endl;

        // Ask the player whether to roll again or hold
        cout << "Do you want to roll again or hold? (r/h): ";
        cin >> choice;

    } while (choice == 'r');

    return score; // Return the score for this turn
}

// Function for computer's turn
int computerTurn() {
    int score = 0;

    while (score < 20) { // Computer will keep rolling until score reaches 20
        int roll = rollDie();
        cout << "Computer rolled: " << roll << endl;

        if (roll == 1) {
            cout << "Computer rolled a 1! Turn ends with 0 points.\n";
            return 0; // If a 1 is rolled, the computer loses its turn and score
        }

        score += roll;
        cout << "Computer's current score: " << score << endl;
    }

    return score; // Return the score for this turn
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int playerTotal = 0, computerTotal = 0;
    const int targetScore = 20; // Target score to win

    while (playerTotal < targetScore && computerTotal < targetScore) {
        cout << "\n--- Your Turn ---\n";
        playerTotal += playerTurn();
        cout << "Your total score: " << playerTotal << endl;

        if (playerTotal >= targetScore) {
            cout << "Congratulations! You win!\n";
            break;
        }

        cout << "\n--- Computer's Turn ---\n";
        computerTotal += computerTurn();
        cout << "Computer's total score: " << computerTotal << endl;

        if (computerTotal >= targetScore) {
            cout << "Computer wins!\n";
            break;
        }
    }

    return 0;
}
