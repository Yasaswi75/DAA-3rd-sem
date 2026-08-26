#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int single = 0;

    for (int i = 0; i < n; i++) {
        single = single ^ arr[i];
    }

    cout << "Single number = " << single << endl;

    return 0;
}
