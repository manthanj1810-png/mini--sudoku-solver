# 0 represents empty cells that the solver needs to fill
grid = [
    [4, 0, 0, 0, 0, 1],
    [0, 0, 3, 0, 6, 0],
    [0, 2, 0, 0, 0, 5],
    [1, 0, 0, 0, 3, 0],
    [0, 4, 0, 2, 0, 0],
    [5, 0, 0, 0, 0, 6]
]

def print_grid(board):
    """Prints the 6x6 board with clear visual boundaries."""
    for i in range(6):
        # Print a horizontal line after every 2 rows
        if i % 2 == 0 and i != 0:
            print("-" * 17)
        for j in range(6):
            # Print a vertical line after every 3 columns
            if j % 3 == 0 and j != 0:
                print("| ", end="")
            print(f"{board[i][j]} ", end="")
        print()

def is_valid(board, row, col, num):
    """Checks if placing 'num' at board[row][col] is valid."""
    # 1. Check the row for duplicates
    for x in range(6):
        if board[row][x] == num:
            return False

    # 2. Check the column for duplicates
    for x in range(6):
        if board[x][col] == num:
            return False

    # 3. Check the 2x3 box
    # Find the starting row (0, 2, or 4) and column (0 or 3) index of the 2x3 box
    start_row = row - row % 2
    start_col = col - col % 3
    for i in range(2):
        for j in range(3):
            if board[i + start_row][j + start_col] == num:
                return False

    return True

def solve_sudoku(board):
    """Solves the Sudoku board using backtracking recursion."""
    for row in range(6):
        for col in range(6):
            # Look for an empty cell
            if board[row][col] == 0:
                # Try placing numbers 1 through 6
                for num in range(1, 7):
                    if is_valid(board, row, col, num):
                        board[row][col] = num  # Tentatively place number

                        # Recursively try to solve the rest of the board
                        if solve_sudoku(board):
                            return True

                        # If it fails later, UNDO the choice (Backtrack)
                        board[row][col] = 0
                
                return False  # Trigger backtracking to previous steps
    return True  # Board completely solved

if __name__ == "__main__":
    print("Original 6x6 Sudoku Puzzle:")
    print_grid(grid)
    print("\nSolving...\n")
    
    if solve_sudoku(grid):
        print("Solved 6x6 Sudoku Puzzle:")
        print_grid(grid)
    else:
        print("No solution exists for this puzzle.")