#include <iostream>
using namespace std;

int main() {
    int N;
    double num, sum = 0, average;

    cout << "Enter N: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;
        sum += num;
    }

    average = sum / N;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}
