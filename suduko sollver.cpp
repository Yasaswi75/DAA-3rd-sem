
#include <iostream>
using namespace std;

int board[9][9];

bool isSafe(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num ||
            board[i][col] == num)
            return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (board[i][j] == num)
                return false;

    return true;
}

bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku())
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter Sudoku (0 for empty cells):\n";

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (solveSudoku()) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}

