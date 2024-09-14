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
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> ah(H), aw(W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) ah[i].insert(j);
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) aw[j].insert(i);
    }

    while (Q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;

        if (ah[i].count(j)) {
            ah[i].erase(j);
            aw[j].erase(i);
            continue;
        }

        auto iu = ah[i].upper_bound(j);
        if (iu != ah[i].end()) {
            aw[*iu].erase(i);
            ah[i].erase(iu);
        }

        auto ju = aw[j].upper_bound(i);
        if (ju != aw[j].end()) {
            ah[*ju].erase(j);
            aw[j].erase(ju);
        }

        auto il = ah[i].lower_bound(j);
        if (il != ah[i].begin()) {
            il--;
            aw[*il].erase(i);
            ah[i].erase(il);
        }

        auto jl = aw[j].lower_bound(i);
        if (jl != aw[j].begin()) {
            jl--;
            ah[*jl].erase(j);
            aw[j].erase(jl);
        }
    }

    int result = 0;
    for (int i = 0; i < H; i++) { result += sz(ah[i]); }
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
