#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 6;
const int BOX_ROWS = 2;
const int BOX_COLS = 3;

// Prints the 6x6 board with clear visual boundaries
void printGrid(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; i++) {
        if (i % BOX_ROWS == 0 && i != 0) {
            cout << "-----------------" << endl;
        }
        for (int j = 0; j < SIZE; j++) {
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
        if (board[row][x] == num) return false;
    }

    // 2. Check the column for duplicates
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) return false;
    }

    // 3. Check the 2x3 sub-grid box
    int startRow = row - row % BOX_ROWS;
    int startCol = col - col % BOX_COLS;
    
    for (int i = 0; i < BOX_ROWS; i++) {
        for (int j = 0; j < BOX_COLS; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Solves the Sudoku board using recursive backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board)) return true;

                        board[row][col] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize an empty 6x6 grid
    vector<vector<int>> grid(SIZE, vector<int>(SIZE, 0));

    cout << "======================================================" << endl;
    cout << "             Custom 6x6 Sudoku Solver                 " << endl;
    cout << "======================================================" << endl;
    cout << "Enter your 6x6 puzzle row by row." << endl;
    cout << "Use numbers 1-6 for filled cells, and 0 for empty spaces." << endl;
    cout << "Separate numbers in a row with spaces.\n" << endl;

    // Take user input for the grid
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter Row " << i + 1 << " (6 numbers): ";
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\n-----------------------------" << endl;
    cout << "Your Inputted Puzzle:" << endl;
    printGrid(grid);
    cout << "-----------------------------\n" << endl;

    cout << "Solving custom puzzle...\n" << endl;

    if (solveSudoku(grid)) {
        cout << "=============================" << endl;
        cout << "      SOLVED PUZZLE" << endl;
        cout << "=============================" << endl;
        printGrid(grid);
    } else {
        cout << "❌ No valid solution exists for this puzzle layout." << endl;
    }

    return 0;
}