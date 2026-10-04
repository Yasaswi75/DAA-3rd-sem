#include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col)
{
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    // Initialize board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0))
    {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
