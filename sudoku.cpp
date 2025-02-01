#include <iostream>
#include <vector>

const int GRID_SIZE = 9;

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int row = 0; row < GRID_SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            std::cout << "---------------------\n";
        }
        for (int column = 0; column < GRID_SIZE; column++) {
            if (column % 3 == 0 && column != 0) {
                std::cout << "| ";
            }
            std::cout << board[row][column] << " ";
        }
        std::cout << "\n";
    }
}

bool isNumberInRow(const std::vector<std::vector<int>>& board, int number, int row) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[row][i] == number) {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(const std::vector<std::vector<int>>& board, int number, int column) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[i][column] == number) {
            return true;
        }
    }
    return false;
}

bool isNumberInBox(const std::vector<std::vector<int>>& board, int number, int row, int column) {
    int localBoxRow = row - row % 3;
    int localBoxColumn = column - column % 3;

    for (int i = localBoxRow; i < localBoxRow + 3; i++) {
        for (int j = localBoxColumn; j < localBoxColumn + 3; j++) {
            if (board[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

bool isValidPlacement(const std::vector<std::vector<int>>& board, int number, int row, int column) {
    return !isNumberInRow(board, number, row) &&
           !isNumberInColumn(board, number, column) &&
           !isNumberInBox(board, number, row, column);
}

bool solveBoard(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            if (board[row][column] == 0) {
                for (int numberToTry = 1; numberToTry <= GRID_SIZE; numberToTry++) {
                    if (isValidPlacement(board, numberToTry, row, column)) {
                        board[row][column] = numberToTry;

                        if (solveBoard(board)) {
                            return true;
                        } else {
                            board[row][column] = 0; // Backtrack
                        }
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

int main() {
    std::vector<std::vector<int>> board = {
        {0, 0, 0, 0, 3, 7, 0, 9, 2},
        {6, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 9, 0, 0, 0, 2, 3, 0, 5},
        {8, 7, 0, 0, 0, 0, 0, 0, 1},
        {0, 2, 0, 9, 0, 1, 0, 4, 0},
        {9, 0, 0, 0, 0, 0, 0, 2, 7},
        {1, 0, 9, 5, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 6},
        {3, 6, 0, 4, 1, 0, 0, 0, 0}
    };

    std::cout << "Unsolved Sudoku:\n";
    printBoard(board);

    if (solveBoard(board)) {
        std::cout << "\nSolved successfully!\n\n";
    } else {
        std::cout << "\nUnsolvable board :(\n";
    }

    printBoard(board);

    return 0;
}
