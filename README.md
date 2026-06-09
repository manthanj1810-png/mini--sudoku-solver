# 6x6 Mini Sudoku Solver

A high-performance C++ command-line application that solves a 6x6 Mini Sudoku puzzle using a recursive Backtracking algorithm.

## Grid Architecture & Rules
Unlike standard 9x9 layouts or 4x4 mini-grids, a 6x6 Sudoku grid utilizes rectangular sub-grids that span **2 rows by 3 columns** ($2 \times 3$). 

To be considered a valid solution, the numbers 1 through 6 must uniquely fill:
* Every individual row
* Every individual column
* Every $2 \times 3$ rectangular sub-grid

## How It Works
The application utilizes a **Depth-First Search (DFS)** approach via recursive backtracking:
1. **Find Empty:** It scans the matrix sequentially to locate an unassigned cell (represented by `0`).
2. **Test Values:** It attempts to place numbers from `1` to `6` into the cell.
3. **Validate Constraints:** The engine checks if the number violates row, column, or sub-grid rules.
4. **Backtrack:** If a path leads to an invalid configuration down the line, the function clears the current cell (`0`) and backtracks to evaluate the next sequence.

## How to Run

### Prerequisites
Make sure you have a C++ compiler installed on your system (such as `g++` via GCC or Clang).

### Compilation and Execution
Open your terminal or command prompt, navigate to the project directory, and run the following commands:

```bash
# 1. Compile the source file
g++ solver.cpp -o solver

# 2. Run the compiled executable
./solver