#include <iostream>
#include <cstring>
using namespace std;

char board[10][10];
bool visited[10][10];

int rows, cols;

bool searchWord(int r, int c, char word[], int index)
{
    // All characters found
    if (word[index] == '\0')
        return true;

    // Check boundaries
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    // Check character and visited status
    if (visited[r][c] || board[r][c] != word[index])
        return false;

    visited[r][c] = true;

    // Move in four directions
    if (searchWord(r + 1, c, word, index + 1) ||
        searchWord(r - 1, c, word, index + 1) ||
        searchWord(r, c + 1, word, index + 1) ||
        searchWord(r, c - 1, word, index + 1))
    {
        return true;
    }

    // Backtrack
    visited[r][c] = false;

    return false;
}

int main()
{
    char word[50];

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter board characters:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }

    cout << "Enter word to search: ";
    cin >> word;

    bool found = false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (searchWord(i, j, word, 0))
            {
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (found)
        cout << "Word exists in the board.";
    else
        cout << "Word does not exist in the board.";

    return 0;
}
