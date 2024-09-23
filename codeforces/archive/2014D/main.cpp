#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> a(N + 1);
    while (K--) {
        int L, R;
        cin >> L >> R;
        a[L - 1]++;
        a[R]--;
    }
    for (int i = 1; i < N; i++) { a[i] += a[i - 1]; }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
