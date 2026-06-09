# 6x6 Mini Sudoku Solver

A high-performance, interactive C++ command-line application that accepts custom $6 \times 6$ Sudoku puzzles from user terminal input and computes solutions instantly using a recursive Backtracking (Depth-First Search) algorithm.

## Grid Architecture & Rules
Unlike standard 9x9 layouts or 4x4 mini-grids, a 6x6 Sudoku grid utilizes rectangular sub-grids that span **2 rows by 3 columns** ($2 \times 3$). 


## 🚀 Features

* **Dynamic User Input:** Accepts unique puzzle layouts row-by-row directly through the standard terminal matrix entry.
* **Smart Grid Boundaries:** Implements precise constraint-checking engineered for custom $2 \times 3$ rectangular sub-grids.
* **Clean Terminal Visualization:** Formats and prints out both the initial state and the calculated solved state with clear horizontal and vertical matrix walls.
* **Robust Error Handling:** Safely detects invalid or unsolvable board configurations and exits gracefully without crashing.


## 🛠️ How It Works (Algorithmic Logic)

The core engine utilizes a recursive **Backtracking Algorithm** which conceptually builds a state tree to explore potential solutions:

1. **Scan Matrix:** The solver scans the grid sequentially from top-left to bottom-right to find an unassigned cell (marked by a `0`).
2. **Sequential Prototyping:** It attempts to assign numbers `1` through `6` to that cell.
3. **Constraint Validation:** For each number, it tests rule validity against current rows, columns, and the $2 \times 3$ target sub-grid block.
4. **Recursive Exploration:** If the number is valid, it marks the cell and recursively attempts to solve the remainder of the matrix.
5. **Backtracking Fallback:** If a branch fails down the tree, the algorithm clears the current selection (`0`) and seamlessly moves to the next number choice.


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