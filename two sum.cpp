
#include <iostream>
using namespace std;

int main() {
    int n, target;
    int nums[100];

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices: " << i << " " << j;
                return 0;
            }
        }
    }

    cout << "No solution found";
    return 0;
}

