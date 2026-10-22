
#include <iostream>
#include <string>
using namespace std;

char board[10][10];
bool visited[10][10];
int rows, cols;
string word;

bool search(int r, int c, int index) {
    if (index == word.length())
        return true;

    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return false;

    if (visited[r][c] || board[r][c] != word[index])
        return false;

    visited[r][c] = true;

    if (search(r + 1, c, index + 1) ||
        search(r - 1, c, index + 1) ||
        search(r, c + 1, index + 1) ||
        search(r, c - 1, index + 1))
        return true;

    visited[r][c] = false;
    return false;
}

int main() {
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter grid characters:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> board[i][j];

    cout << "Enter word to search: ";
    cin >> word;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0]) {
                if (search(i, j, 0)) {
                    cout << "Word found";
                    return 0;
                }
            }
        }
    }

    cout << "Word not found";
    return 0;
}

