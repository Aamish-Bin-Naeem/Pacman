#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

// Function prototypes
int UserPrompt();
void grid_one();
void mapDisplay();

const int GRID_HEIGHT = 18;
const int GRID_WIDTH = 32;

char map[GRID_HEIGHT][GRID_WIDTH] = {
    "_______________________________",
    "|                             |",
    "|                             |",
    "|__ ___________ __   _________|",
    "|   |                         |",
    "| | |--  |              |     |",
    "| |      |    |---  |   |  |  |",
    "| |  ----|    |      -  |     |",
    "| |           |---  |      |  |",
    "| |----  --          --       |",
    "|          ------  ------- ---|",
    "|               |             |",
    "|_ --- ----      ---   -------|",
    "|                             |",
    "| ___       |---     |        |",
    "|       |---|        |    ----|",
    "|                    |        |",
    "_______________________________"
};

/* void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
} */

int main() {
    int user_input = UserPrompt();

    switch (user_input) {
        case 1: {
            // Get user's name
            string playerName;
            cout << "\nEnter your name: ";
            cin.ignore();
            getline(cin, playerName);

            // Display 'dive-in game' options
            cout << "\nPress 1 to dive into the game:\n";

            int selectedGrid;
            cout << "Enter your choice: ";
            cin >> selectedGrid;

            // Process the selected grid
            switch (selectedGrid) {
                case 1:
                    grid_one();
                    break;

                default:
                    cout << "Invalid grid choice.\n";
                    break;
            }

            break;
        }
        case 2:
            // Exit the program
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid input. Exiting the program.\n";
            return 0;
    }

    return 0;
}

int UserPrompt() {
    cout << "Welcome to Pacman!\n\n";
    cout << "1- Start Game\n";
    cout << "2- Exit\n";

    int user_input;
    do {
        cout << "Enter your choice (1-2): ";
        cin >> user_input;
    } while (user_input < 1 || user_input > 2);

    return user_input;
}

void grid_one() {
    // initial character position
    int posx = 1;
    int posy = 1;
    map[posx][posy] = 'P'; // 'P' = the character

    while (true) {
        // Display map
        mapDisplay();

        // user input for movement
        char move = _getch(); // capture arrow key presses

        // Update character position based on user input
        switch (move) {
            case 72: // Up arrow key
                if (posx > 0 && map[posx - 1][posy] == ' ') {
                    map[posx][posy] = ' ';
                    posx--;
                    map[posx][posy] = 'P';
                }
                break;
            case 75: // Left arrow key
                if (posy > 0 && map[posx][posy - 1] == ' ') {
                    map[posx][posy] = ' ';
                    posy--;
                    map[posx][posy] = 'P';
                }
                break;
            case 80: // Down arrow key
                if (posx < GRID_HEIGHT - 1 && map[posx + 1][posy] == ' ') {
                    map[posx][posy] = ' ';
                    posx++;
                    map[posx][posy] = 'P';
                }
                break;
            case 77: // Right arrow key
                if (posy < GRID_WIDTH - 1 && map[posx][posy + 1] == ' ') {
                    map[posx][posy] = ' ';
                    posy++;
                    map[posx][posy] = 'P';
                }
                break;
            default:
                break;
        }
    }
}

void mapDisplay() {
    system("CLS"); // Clear the console screen
    // Display the map
    for (int i = 0; i < GRID_HEIGHT; i++) {
        cout << map[i] << endl;
    }
}
