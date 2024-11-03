#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector a(K, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) { cin >> a[j][i]; }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; j++) {
            a[j][i] = a[j][i] | a[j][i - 1];
        }
    }

    while (Q--) {
        int M;
        cin >> M;
        int l = 0, r = N;
        while (M--) {
            int R, c;
            char o;
            cin >> R >> o >> c;
            R--;
            assert(R < K);
            if (o == '<') {
                r = min(r,
                        (int)(lower_bound(a[R].begin(),
                                          a[R].end(), c) -
                              a[R].begin()));
            }
            if (o == '>') {
                l = max(l,
                        (int)(upper_bound(a[R].begin(),
                                          a[R].end(), c) -
                              a[R].begin()));
            }
        }
        cout << (l < r ? l + 1 : -1) << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
