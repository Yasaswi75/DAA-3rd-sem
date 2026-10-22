
#include <iostream>
#include <cmath>
using namespace std;

int n, pos[20];
int countSolutions = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == col ||
            abs(pos[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        countSolutions++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            pos[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Enter N between 1 and 20";
        return 0;
    }

    solve(0);

    cout << "Number of solutions: " << countSolutions;
    return 0;
}

