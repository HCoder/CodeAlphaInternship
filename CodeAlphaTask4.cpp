#include <iostream>
using namespace std;

// Function prototypes
void drawSquare();
void drawRhombus();
void drawTriangle();
void drawHeart();

void displayMenu() {
    cout << "********************************************\n";
    cout << "*          Welcome to Console Art!         *\n";
    cout << "********************************************\n";
    cout << "* Please choose a shape to draw:           *\n";
    cout << "* 1. Square                                *\n";
    cout << "* 2. Rhombus                               *\n";
    cout << "* 3. Triangle                              *\n";
    cout << "* 4. Heart                                 *\n";
    cout << "* 5. Exit                                  *\n";
    cout << "********************************************\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                drawSquare();
                break;
            case 2:
                drawRhombus();
                break;
            case 3:
                drawTriangle();
                break;
            case 4:
                drawHeart();
                break;
            case 5:
                cout << "Thank you for using Console Art! Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to draw a square with borders only
void drawSquare() {
    const int size = 5;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Function to draw an empty rhombus
void drawRhombus() {
    const int size = 7;
    int n = size / 2;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j)
            cout << "  ";
        for (int j = 0; j < 2 * i + 1; ++j) {
            if (j == 0 || j == 2 * i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j)
            cout << "  ";
        for (int j = 0; j < 2 * i + 1; ++j) {
            if (j == 0 || j == 2 * i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Function to draw a triangle with borders only
void drawTriangle() {
    const int height = 5;
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height - i; ++j)
            cout << "  ";
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (j == 1 || j == 2 * i - 1 || i == height)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// Function to draw a heart with borders only
void drawHeart() {
    const int size = 6;
    // Top part of the heart
    for (int i = size / 2; i < size; i += 2) {
        for (int j = 1; j < size - i; j += 2) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        for (int j = 1; j <= size - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    // Bottom part of the heart
    for (int i = size; i >= 1; --i) {
        for (int j = i; j < size; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= (i * 2) - 1; ++j) {
            if (j == 1 || j == (i * 2) - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
