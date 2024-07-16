#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int result = s.size();

    array<bool, 26> seen = {0};

    for (char c : s) {
        if (seen[c - 'a']) {
            result -= 2;
            fill(seen.begin(), seen.end(), 0);
        } else {
            seen[c - 'a'] = 1;
        }
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
