#include <ctime>
#include <iostream>
#include <limits>
#include <random>

namespace constants {
constexpr int maxGuesses{7};
constexpr int minimum{0};
constexpr int maximum{100};
}  // namespace constants

int takeGuess(int guessIndex) {
    int guess{};
    // Loop until we get a valid guess.
    while (true) {
        std::cout << "Guess #" << guessIndex << ": ";
        std::cin >> guess;
        // check for failed extraction
        if (std::cin.fail()) {
            // clear fail state
            std::cin.clear();
            // clear buffer including entered new line.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Oops, that input was invalid. Please try again."
                      << '\n';
        } else {
            // Clear buffer of any remaining stuff, including the entered new
            // line.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return guess;
        }
    }
}

int main() {
    std::cout << "Let's play a game. I am thinking of a number. You have "
              << constants::maxGuesses << " tries to guess what it is." << '\n';

    // main game loop
    bool playing{true};
    while (playing) {
        // Generate random target number.
        // Init mersenne twister based on clock time.
        std::mt19937 mersenne{
            static_cast<std::mt19937::result_type>(std::time(nullptr))};
        // Create reusable random number generator.
        std::uniform_int_distribution<> die{constants::minimum,
                                            constants::maximum};
        const int targetNumber = die(mersenne);

        // Ask for guesses until all tries are used or guess is correct.
        bool won{};
        for (int guessIndex{0}; guessIndex < constants::maxGuesses;
             guessIndex++) {
            int guess{takeGuess(guessIndex)};
            if (guess == targetNumber) {
                std::cout << "Correct! You win!" << '\n';
                won = true;
                break;
            } else if (guess < targetNumber) {
                std::cout << "Your guess is too low." << '\n';
            } else {
                std::cout << "Your guess is too high." << '\n';
            }
        }

        // Display a lose message if they did not win.
        if (!won) {
            std::cout << "Sorry, you lose. The correct number was "
                      << targetNumber << "." << '\n';
        }

        // Ask if they would like to play again.
        std::cout << "Would you like to play again (y/n)? ";
        char playAgain{};
        std::cin >> playAgain;
        if (playAgain == 'y') {
            continue;
        } else {
            break;
        }
    }
    return 0;
}
