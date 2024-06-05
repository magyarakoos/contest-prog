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

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    multiset<int> diffS, loneS;

    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            diffS.insert(B[i]);
        } else {
            loneS.insert(A[i]);
        }
    }

    int M;
    cin >> M;
    vector<int> D(M);
    for (int& x : D) cin >> x;

    bool ok = 0;
    for (int i = M - 1; ~i; i--) {
        if (diffS.count(D[i])) {
            ok = 1;
            diffS.erase(diffS.find(D[i]));
            continue;
        }
        if (!ok) {
            if (loneS.count(D[i])) {
                ok = 1;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << (diffS.empty() ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}