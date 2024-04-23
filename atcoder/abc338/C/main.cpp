#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N), AC(N);
    for (int& x : Q) cin >> x;
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    
    int mn_a = INT_MAX;
    for (int i = 0; i < N; i++) {
        AC[i] = Q[i] / A[i];
        mn_a = min(mn_a, AC[i]);
    }

    int res = 0;
    for (int curr_a = 0; curr_a <= mn_a; curr_a++) {
        vector<int> Q_left = Q;
        for (int i = 0; i < N; i++) {
            Q_left[i] -= curr_a * A[i];
        }
        vector<int> BC(N);
        int mn_b = INT_MAX;
        for (int i = 0; i < N; i++) {
            BC[i] = Q_left[i] / B[i];
            mn_b = min(mn_b, BC[i]);
        }
        res = max(res, curr_a + mn_b);
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}