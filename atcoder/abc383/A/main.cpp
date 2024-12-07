#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> T(N), V(N);
    for (int i = 0; i < N; i++) cin >> T[i] >> V[i];
    int result = V[0];
    for (int i = 1; i < N; i++) {
        result = max(0, result - (T[i] - T[i - 1])) + V[i];
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
