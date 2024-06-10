#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayWelcomeMessage();
int getUserChoice();
void playGame(const vector<string>& words, const vector<vector<string>>& hints, int choice);

int main() {
    // Vector of words
    vector<string> words = {"computer", "pizza", "bicycle", "elephant", "river", "guitar", "mountain", "book", "piano", "airplane"};

    // Vector of vectors of hints corresponding to each word
    vector<vector<string>> hints = {
        {"It's an electronic device.", "It's used for computing.", "It has a screen.", "It has a keyboard.", "It can connect to the internet."},
        {"It's a type of food.", "It's often round.", "It has cheese.", "It's often delivered.", "It originated from Italy."},
        {"It's a means of transport.", "It has two wheels.", "You pedal to move it.", "It can have gears.", "It's often used for exercise."},
        {"It's an animal.", "It's very large.", "It has a trunk.", "It lives in Africa and Asia.", "It has tusks."},
        {"It's a natural water body.", "It's flowing.", "It's found in nature.", "It's often long and wide.", "It can be crossed by bridges."},
        {"It's a musical instrument.", "It has strings.", "It's often used in rock music.", "It's played by strumming.", "It can be electric or acoustic."},
        {"It's a natural landform.", "It's very tall.", "It's part of Earth's surface.", "It can be climbed.", "It often has snow at the top."},
        {"It's an item used for reading.", "It has pages.", "It has a cover.", "It's often found in libraries.", "It can be fiction or non-fiction."},
        {"It's a musical instrument.", "It has keys.", "It's often large.", "It can be grand or upright.", "It's played by pressing keys."},
        {"It's a means of transport.", "It flies.", "It has wings.", "It can carry passengers.", "It takes off from airports."}
    };

    displayWelcomeMessage();
    
    int choice = getUserChoice();
    playGame(words, hints, choice);

    return 0;
}

void displayWelcomeMessage() {
    cout << "********************************************\n";
    cout << "*         Welcome to the Word Guessing Game!         *\n";
    cout << "********************************************\n";
    cout << "* Choose a random number between 0 and 9.          *\n";
    cout << "********************************************\n";
}

int getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice < 0 || choice > 9) {
        cout << "Invalid choice. Please enter a number between 0 and 9: ";
        cin >> choice;
    }
    return choice;
}

void playGame(const vector<string>& words, const vector<vector<string>>& hints, int choice) {
    string word = words[choice];
    vector<string> wordHints = hints[choice];

    cout << "You have chosen a word. Let's start the guessing game!\n";
    cout << "You will get 5 hints and 5 chances to guess the word.\n";

    for (int i = 0; i < 5; ++i) {
        cout << "Hint " << i + 1 << ": " << wordHints[i] << endl;
        cout << "Enter your guess: ";
        string guess;
        cin >> guess;

        if (guess == word) {
            cout << "Congratulations! You guessed the word correctly.\n";
            return;
        } else {
            cout << "Incorrect guess. ";
            if (i < 4) {
                cout << "Here's another hint.\n";
            } else {
                cout << "You've used all your hints.\n";
            }
        }
    }

    cout << "Sorry, you didn't guess the word. The correct word was: " << word << endl;
}
