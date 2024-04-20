#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for (char c : s) m[c]++;
    map<int, int> m2;
    for (auto [k, v] : m) m2[v]++;
    for (auto [k, v] : m2) {
        if (v != 2) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
}
