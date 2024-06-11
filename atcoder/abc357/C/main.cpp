#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

void carp(vector<string>& carpet, int K, int i) {
    if (K) {
        int pw = 1;
        for (int i = 0; i < K; i++) pw *= 3;
        int a = pw / 3;

        for (int j = 0; j < 3; j++) {
            carp(carpet, K - 1, i);
        }

        carp(carpet, K - 1, i + a);
        for (int j = i + a; j < i + a * 2; j++) {
            carpet[j] += string(a, '.');
        }
        carp(carpet, K - 1, i + a);

        for (int j = 0; j < 3; j++) {
            carp(carpet, K - 1, i + a * 2);
        }
    } else {
        carpet[i] += '#';
    }
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    int pw = 1;
    for (int i = 0; i < N; i++) pw *= 3;
    vector<string> carpet(pw, "");
    carp(carpet, N, 0);
    for (const string& line : carpet) {
        cout << line << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}