#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    char c;
    cin >> c;
    if (!isupper(c)) {
        cout << "No";
        exit(0);
    }
    string s;
    cin >> s;
    for (char c : s) {
        if (!islower(c)) {
            cout << "No";
            exit(0);
        }
    };
    cout << "Yes";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
