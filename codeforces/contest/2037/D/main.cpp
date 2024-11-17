#include <bits/stdc++.h>

using namespace std;
#define int int64_t

#define cases 1
void solve() {
    int N, M, End;
    cin >> N >> M >> End;

    vector<int> L(N), R(N), X(M), V(M);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
    for (int i = 0; i < M; i++) cin >> X[i] >> V[i];

    int result = 0, power = 1;
    multiset<int> a;
    for (int i = 0, j = 0; j < N; j++) {
        while (i < M && X[i] < L[j]) { a.insert(V[i++]); }
        while (power < R[j] - L[j] + 2) {
            if (a.empty()) {
                cout << "-1\n";
                return;
            }
            result++;
            power += *a.rbegin();
            a.erase(a.find(*a.rbegin()));
        }
    }

    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
