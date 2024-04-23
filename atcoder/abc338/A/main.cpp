#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    string s;
    cin >> s;
    cout << (s[0] >= 'A' && all_of(s.begin() + 1, s.end(), [](char c){return c <= 'z';}) ?
    "Yes" : "No");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}