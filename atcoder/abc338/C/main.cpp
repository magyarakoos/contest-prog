#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N), AC(N), BC(N);
    for (int& x : Q) cin >> x;
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    
    int mn_a = INT_MAX, mn_b = INT_MAX;
    for (int i = 0; i < N; i++) {
        AC[i] = Q[i] / A[i];
        BC[i] = Q[i] / B[i];
        mn_a = min(mn_a, AC[i]);
        mn_b = min(mn_b, BC[i]);
    }

    int res = 0;

    for (int curr_a = 0; curr_a <= mn_a; curr_a++) {
        
    }
    
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}