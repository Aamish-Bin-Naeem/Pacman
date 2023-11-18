#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int UserPrompt();
void grid_one();
void pacman();

char map[18][32];

int main() {
    int user_input = UserPrompt();

    switch (user_input) {
        case 1: {
            // Get user's name
            string playerName;
            cout << "\nEnter your name: ";
            cin.ignore();
            getline(cin, playerName);

            // Display grid options
            cout << "\nPress 1 to dive in the game:\n";

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
            // Show leaderboard stats
            break;
        case 3:
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
    // cout << "===========================================\n\n";
    cout << "Welcome to Pacman!\n\n";
    cout << "1- Start Game\n";
    cout << "2- Leaderboard Stats\n";
    cout << "3- Exit\n";

    int user_input;
    do {
        cout << "Enter your choice (1-3): ";
        cin >> user_input;
    } while (user_input < 1 || user_input > 3);

    return user_input;
}

void grid_one() {
	int x, y;
    for (int i=0;i<10;i++) {
    	for (int j=0; j<15; j++) {
    		x = rand() %32;
    		y = rand() %18;
    	if ( i%5 == 0) {
		map[x][y] = '|';
	    } else {
    		map[x][y] = '-';
		}
	}
} 

	

	for (int i = 0; i< 18; i++) {
		for ( int j = 0; j<32; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	
	char map_copy[18][32];
	
	for (int i = 0; i< 18; i++) {
		for ( int j = 0; j<32; j++) {
			map_copy [i][j] = map[i][j];
		}
	}

  }
  
  void pacman() {
  	map[0][1] = 'P';
  }


