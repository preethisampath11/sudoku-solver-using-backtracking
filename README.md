# Sudoku Solver  

This is a simple C++ program that solves a **9x9 Sudoku puzzle** using **backtracking**. The program takes an incomplete Sudoku board, fills in the missing numbers while following Sudoku rules, and prints the solved board.  

## Features  

- Uses **backtracking** to efficiently solve the Sudoku puzzle  
- Validates placements using row, column, and 3x3 box constraints  
- Prints the Sudoku board before and after solving  

## How It Works  

1. The program initializes a 9x9 Sudoku board with some pre-filled numbers and empty cells (represented by `0`).  
2. It attempts to fill each empty cell with numbers `1-9`, ensuring that they comply with Sudoku rules.  
3. If a valid number is found, it recursively moves to the next empty cell. If no valid number exists, it backtracks.  
4. Once the board is fully filled, the solution is printed.  

## Code Structure  

- `printBoard()`: Prints the Sudoku board in a readable format.  
- `isNumberInRow()`, `isNumberInColumn()`, `isNumberInBox()`: Helper functions to check number validity.  
- `isValidPlacement()`: Checks whether a number can be placed at a given position.  
- `solveBoard()`: Recursively solves the Sudoku using **backtracking**.  
- `main()`: Initializes a sample Sudoku board and calls the solver.  

## How to Run  

1. **Compile the code** using a C++ compiler:  

   ```bash
   g++ sudoku_solver.cpp -o sudoku_solver
   ```

2. **Run the program**:  

   ```bash
   ./sudoku_solver
   ```

## Example  

**Input (Unsolved Sudoku Board)**  

```
0  0  0 | 0  3  7 | 0  9  2  
6  3  0 | 0  0  0 | 0  0  0  
0  9  0 | 0  0  2 | 3  0  5  
---------------------  
8  7  0 | 0  0  0 | 0  0  1  
0  2  0 | 9  0  1 | 0  4  0  
9  0  0 | 0  0  0 | 0  2  7  
---------------------  
1  0  9 | 5  0  0 | 0  7  0  
0  0  0 | 0  0  0 | 0  8  6  
3  6  0 | 4  1  0 | 0  0  0  
```

**Output (Solved Sudoku Board)**  

```
5  1  2 | 6  3  7 | 4  9  2  
6  3  7 | 1  5  9 | 8  2  4  
4  9  8 | 3  7  2 | 3  1  5  
---------------------  
8  7  6 | 2  4  5 | 9  3  1  
2  2  5 | 9  8  1 | 7  4  3  
9  4  3 | 7  6  8 | 5  2  7  
---------------------  
1  8  9 | 5  2  3 | 6  7  4  
7  5  4 | 1  9  6 | 2  8  6  
3  6  1 | 4  1  2 | 9  5  8  
```

## Contributions  

Feel free to fork this repository, submit issues, or suggest improvements!  
