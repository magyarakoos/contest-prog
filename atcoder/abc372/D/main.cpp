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

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int& x : H) cin >> x;

    stack<int> s{{H[N - 1]}};

    vector<int> result(N);

    for (int i = N - 2; ~i; i--) {
        result[i] = s.size();

        while (!s.empty() && s.top() < H[i]) s.pop();
        s.push(H[i]);
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
