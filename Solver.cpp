#include <iostream>
#include <vector>

using namespace std;

// Define the grid size constants
const int SIZE = 6;
const int BOX_ROWS = 2;
const int BOX_COLS = 3;

// Prints the 6x6 board with clear visual boundaries
void printGrid(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; i++) {
        // Print a horizontal line after every 2 rows
        if (i % BOX_ROWS == 0 && i != 0) {
            cout << "-----------------" << endl;
        }
        for (int j = 0; j < SIZE; j++) {
            // Print a vertical line after every 3 columns
            if (j % BOX_COLS == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Checks if placing 'num' at board[row][col] satisfies Sudoku rules
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // 1. Check the row for duplicates
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // 2. Check the column for duplicates
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // 3. Check the 2x3 sub-grid box
    // Find the starting row (0, 2, or 4) and column (0 or 3) index of the box
    int startRow = row - row % BOX_ROWS;
    int startCol = col - col % BOX_COLS;
    
    for (int i = 0; i < BOX_ROWS; i++) {
        for (int j = 0; j < BOX_COLS; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Solves the Sudoku board using recursive backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Look for an empty cell (represented by 0)
            if (board[row][col] == 0) {
                // Try placing numbers 1 through 6
                for (int num = 1; num <= SIZE; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // Make a tentative assignment

                        // Recursively try to solve the rest of the board
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // If it doesn't lead to a solution, UNDO (Backtrack)
                        board[row][col] = 0;
                    }
                }
                return false; // Triggers backtracking to the previous step
            }
        }
    }
    return true; // Puzzle solved completely
}

int main() {
    // 0 represents empty cells that the solver needs to fill
    vector<vector<int>> grid = {
        {4, 0, 0, 0, 0, 1},
        {0, 0, 3, 0, 6, 0},
        {0, 2, 0, 0, 0, 5},
        {1, 0, 0, 0, 3, 0},
        {0, 4, 0, 2, 0, 0},
        {5, 0, 0, 0, 0, 6}
    };

    cout << "Original 6x6 Sudoku Puzzle:" << endl;
    printGrid(grid);
    cout << "\nSolving...\n" << endl;

    if (solveSudoku(grid)) {
        cout << "Solved 6x6 Sudoku Puzzle:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for this puzzle." << endl;
    }

    return 0;
}