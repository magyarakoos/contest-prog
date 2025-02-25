#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    set<int> seen;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B.size(); j++) {
            if (!seen.count(A[i] + B[j])) {
                seen.insert(A[i] + B[j]);
                B.erase(B.begin() + j);
                break;
            }
        }
    }
    if (seen.size() >= 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
