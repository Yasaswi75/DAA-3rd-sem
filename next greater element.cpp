#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100], result[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {

        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        s.push(arr[i]);
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
