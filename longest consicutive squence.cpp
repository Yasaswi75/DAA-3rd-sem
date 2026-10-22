
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, nums[100];

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (n == 0) {
        cout << "Longest length: 0";
        return 0;
    }

    sort(nums, nums + n);

    int longest = 1, current = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
            current++;
        else
            current = 1;

        longest = max(longest, current);
    }

    cout << "Longest consecutive length: " << longest;
    return 0;
}

