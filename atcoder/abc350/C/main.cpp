#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        m[A[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        if (A[i] != i) {
            A[m[i]] = A[i];
        }
    }
//     for (auto [l, r] : result) cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}