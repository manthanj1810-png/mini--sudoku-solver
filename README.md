# 6x6 Mini Sudoku Solver

A lightweight Python command-line application that solves 6x6 Sudoku puzzles using a Backtracking algorithm.

## How It Works
The algorithm uses **recursive backtracking** to find empty cells, tests valid numbers from 1 to 6, and verifies them against the standard Sudoku constraints (Row, Column, and $2 \times 3$ Box sub-grids). If a number violates a rule later in the calculation, the algorithm backtracks and tries the next configuration.

## Features
* Clean terminal-based grid visualization.
* Custom constraint checking for rectangular $2 \times 3$ sub-grids.
* Quick execution time using recursive depth-first exploration.

## How to Run
Ensure you have Python installed on your system, then clone the repository and run:
```bash
python solver.py