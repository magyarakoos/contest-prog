#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 1e18;

ll range_min(const vector<ll>& v, int l, int r) {
    ll mn = v[l];
    for (int i = l + 1; i <= r; i++) {
        smin(mn, v[i]);
    }
    return mn;
}

#define cases 1
void solve() {
    int N, K;
    cin >> N >> K;
    vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    // legfeljebb N - 1 műveletet tudunk elvégezni
    smin(K, N - 1);

    // dp[i][j] = v[1..i] összege, amennyiben már j műveletet elvégeztünk
    vector dp(N + 1, vector<ll>(K + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        // ahol i - 1 < K, ott nem tudjuk elvégezni az összes műveletet
        for (int j = 0; j <= min(i - 1, K); j++) {
            // innen nézve az előző x számot vonjuk össze
            // ez evidens, hogy legfeljebb j lehet
            for (int k = 0; k <= j; k++) {
                smin(dp[i][j],
                    dp[max(i - (k + 1), 0)][j - k] +
                    range_min(v, i - k, i) * (k + 1)
                );
            }
        }
    }

    cout << *min_element(all(dp[N])) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
