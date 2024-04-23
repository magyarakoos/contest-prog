#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    char c;
    cin >> c >> c >> c;
    int N;
    cin >> N;
    cout << (N >= 1 && N <= 349 && N != 316 ? "Yes" : "No");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}