#include <iostream>
using namespace std;

int main()
{
    // ── REQUIREMENT 1: 2D Array ────────────────────────────────
    // This is a 3x3 table (3 rows, 3 columns) to store the board
    // Instead of 9 separate variables like box1, box2... we use board[row][col]
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice;
    char player = 'X';
    int moves = 0;
    bool win = false;

    // ── REQUIREMENT 3: Menu ────────────────────────────────────
    int menuChoice;

    cout << "=============================" << endl;
    cout << "   TIC TAC TOE - ADVANCED    " << endl;
    cout << "=============================" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. How to Play" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> menuChoice;

    if (menuChoice == 2)
    {
        cout << endl;
        cout << "HOW TO PLAY:" << endl;
        cout << "Players take turns picking a box number (1-9)" << endl;
        cout << "First to get 3 in a row wins!" << endl;
        cout << endl;
        cout << " 1 | 2 | 3" << endl;
        cout << "---|---|---" << endl;
        cout << " 4 | 5 | 6" << endl;
        cout << "---|---|---" << endl;
        cout << " 7 | 8 | 9" << endl;
        cout << endl;
        cout << "Enter 1 to start: ";
        cin >> menuChoice;
    }

    if (menuChoice == 3)
    {
        cout << "Goodbye!" << endl;
        return 0;
    }

    cout << endl;
    cout << "Player 1 = X    Player 2 = O" << endl;
    cout << "Pick a number from 1 to 9" << endl;

    // ── MAIN GAME LOOP ─────────────────────────────────────────
    while (win == false && moves < 9)
    {
        // ── REQUIREMENT 2: Nested loops to show the board ──────
        // ── REQUIREMENT 4: Board state shown every turn ────────
        cout << endl;
        cout << "Move number: " << moves << endl;

        for (int row = 0; row < 3; row++)          // outer loop: go through each row
        {
            cout << " ";
            for (int col = 0; col < 3; col++)      // inner loop: go through each column
            {
                cout << board[row][col];            // print what's in this cell
                if (col < 2)
                    cout << " | ";
            }
            cout << endl;
            if (row < 2)
                cout << "---|---|---" << endl;
        }

        cout << endl;
        cout << "Player " << player << " enter box number: ";
        cin >> choice;

        // Convert 1-9 number to row and column in the 2D array
        // Example: choice 5 → row = (5-1)/3 = 1,  col = (5-1)%3 = 1
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Validate move
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Invalid! Box taken or wrong number. Try again." << endl;
            continue;
        }

        board[row][col] = player;   // Place X or O in the 2D array
        moves++;

        // Check all rows for a win
        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
                win = true;
        }

        // Check all columns for a win
        for (int c = 0; c < 3; c++)
        {
            if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
                win = true;
        }

        // Check both diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            win = true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            win = true;

        // Switch player if no win yet
        if (win == false)
        {
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
    }

    // ── REQUIREMENT 4: Show final board state ──────────────────
    cout << endl;
    cout << "=== FINAL BOARD ===" << endl;

    for (int row = 0; row < 3; row++)
    {
        cout << " ";
        for (int col = 0; col < 3; col++)
        {
            cout << board[row][col];
            if (col < 2)
                cout << " | ";
        }
        cout << endl;
        if (row < 2)
            cout << "---|---|---" << endl;
    }

    cout << endl;
    if (win == true)
        cout << "Player " << player << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}
