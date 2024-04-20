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
    vector<array<int, 2>> result;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] != i) {
            result.push_back({i, m[i]});
            A[m[i]] = A[i]; // pipa
            m[A[i]] = i;
        }
    }
    cout << result.size() << "\n";
    for (auto [l, r] : result) cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}