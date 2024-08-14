#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

ll calc(const vector<bool>& a, int N) {
    array<ll, 2> m{1, 0};  // {even, odd}
    int sum = 0;
    ll result = 0;

    for (int i = 0; i < N; i++) {
        sum += a[i];
        if (sum & 1) {
            result += m[0];
            m[1]++;
        } else {
            result += m[1];
            m[0]++;
        }
    }

    return result - accumulate(all(a), 0);
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    ll result = 0;
    for (int i = 0; i < 28; i++) {
        vector<bool> b(N);
        for (int j = 0; j < N; j++) {
            b[j] = a[j] >> i & 1;
        }
        result += (1 << i) * calc(b, N);
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
