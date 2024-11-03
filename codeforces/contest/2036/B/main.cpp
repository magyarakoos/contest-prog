#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int N, K;
    cin >> N >> K;
    map<int, int> m;
    int sum = 0;
    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;
        sum += B;
        m[A] += B;
    }
    if (N >= m.size()) {
        cout << sum << "\n";
        return;
    }
    vector<int> a;
    for (auto [br, tot] : m) { a.push_back(tot); }
    sort(a.rbegin(), a.rend());
    int result = 0;
    assert(a.size() >= N);
    for (int i = 0; i < N; i++) { result += a[i]; }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
