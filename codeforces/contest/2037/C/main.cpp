#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int N;
    cin >> N;
    if (N < 5) {
        cout << "-1\n";
        return;
    }
    for (int i = 7; i <= N; i += 2) { cout << i << " "; }
    cout << "1 3 5 4 2 ";
    for (int i = 6; i <= N; i += 2) { cout << i << " "; }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
