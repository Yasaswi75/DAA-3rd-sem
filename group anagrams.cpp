
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string word;
    map<string, vector<string> > groups;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter words: ";
    for (int i = 0; i < n; i++) {
        cin >> word;
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    cout << "Grouped Anagrams:\n";
    for (map<string, vector<string> >::iterator it = groups.begin();
         it != groups.end(); ++it) {
        for (int i = 0; i < it->second.size(); i++)
            cout << it->second[i] << " ";
        cout << endl;
    }

    return 0;
}

