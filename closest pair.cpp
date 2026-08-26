#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minDiff = abs(arr[0] - arr[1]);
    int value1 = arr[0];
    int value2 = arr[1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int diff = abs(arr[i] - arr[j]);

            if (diff < minDiff) {
                minDiff = diff;
                value1 = arr[i];
                value2 = arr[j];
            }
        }
    }

    cout << "Closest pair = " << value1 << " and " << value2 << endl;
    cout << "Minimum difference = " << minDiff;

    return 0;
}
