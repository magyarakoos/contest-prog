#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    map<int, int> m;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        m[A[i]] = i;
    }
    vector<array<int, 2>> result;
    for (int i = 0; i < N; i++) {
        if (A[i] != i) {
            result.push_back({i, m[i]});
            swap(A[i], A[m[i]]);
        }
    }
    cout << result.size() << "\n";
    for (auto [l, r] : result) cout << l << " " << r << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}