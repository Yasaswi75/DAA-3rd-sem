
#include <iostream>
#include <string>
using namespace std;

int maze[10][10], n;
bool visited[10][10];
string path;
bool found = false;

void solve(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n ||
        maze[r][c] == 0 || visited[r][c])
        return;

    if (r == n - 1 && c == n - 1) {
        cout << path << endl;
        found = true;
        return;
    }

    visited[r][c] = true;

    path += 'D';
    solve(r + 1, c);
    path.erase(path.size() - 1);

    path += 'L';
    solve(r, c - 1);
    path.erase(path.size() - 1);

    path += 'R';
    solve(r, c + 1);
    path.erase(path.size() - 1);

    path += 'U';
    solve(r - 1, c);
    path.erase(path.size() - 1);

    visited[r][c] = false;
}

int main() {
    cout << "Enter maze size: ";
    cin >> n;

    cout << "Enter maze (1=open, 0=blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    if (maze[0][0] == 0 || maze[n-1][n-1] == 0) {
        cout << "No path exists";
        return 0;
    }

    cout << "Paths (D=Down, L=Left, R=Right, U=Up):\n";
    solve(0, 0);

    if (!found)
        cout << "No path exists";

    return 0;
}

