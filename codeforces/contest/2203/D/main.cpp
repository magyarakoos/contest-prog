#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    const int MAXN = n + m + 5;
    vector<int> muls(MAXN);
    vector<int> ha(MAXN), hb(MAXN);
    for (int x : a) ha[x]++;
    for (int x : b) hb[x]++;
    for (int i = 0; i < MAXN; i++) {
        if (ha[i]) {
            for (int j = i; j < MAXN; j += i) {
                muls[j] += ha[i];
            }
        }
    }
    // for (int i = 0; i < 15; i++) { cout << muls[i] << "
    // "; } cout << "\n";

    int alice = 0, bob = 0, both = 0;
    for (int i = 0; i < MAXN; i++) {
        if (!hb[i]) continue;
        if (muls[i] == 0) {
            bob += hb[i];
        } else if (muls[i] == n) {
            alice += hb[i];
        } else {
            both += hb[i];
        }
    }
    // cout << alice << " " << bob << " " << both << "\n";
    int i = both;
    while (1) {
        if (i % 2) {
            if (bob == 0) {
                cout << "Alice\n";
                return;
            }
            bob--;
        } else {
            if (alice == 0) {
                cout << "Bob\n";
                return;
            }
            alice--;
        }
        i++;
    }
    assert(0);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
