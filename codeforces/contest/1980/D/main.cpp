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

bool is_increasing(const vector<int>& v, int i, int j) {
    for (; i < j; i++) {
        if (v[i] > v[i + 1]) return 0;
    }
    return 1;
}

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> v(N), vgcd(N - 1);
    for (int& x : v) cin >> x;

    for (int i = 0; i < N - 1; i++) {
        vgcd[i] = gcd(v[i], v[i + 1]);
    }

    vector<bool> pgcd(N);
    pgcd[0] = 1;
    pgcd[1] = 1;
    for (int i = 1; i < N - 1; i++) {
        pgcd[i + 1] = pgcd[i] && vgcd[i - 1] <= vgcd[i];
    }

    vector<bool> sgcd(N);
    sgcd[N - 1] = 1;
    sgcd[N - 2] = 1;
    for (int i = N - 3; ~i; i--) {
        sgcd[i] = sgcd[i + 1] && vgcd[i + 1] >= vgcd[i];
    }
    reverse(all(sgcd));

    if (is_increasing(vgcd, 1, N - 2) || is_increasing(vgcd, 0, N - 3)) {
        cout << "YES\n";
        return;
    }

    // which array element to delete
    for (int i = 1; i < N - 1; i++) {
        if (pgcd[i - 1] && sgcd[N - i - 2]) {
            vector<int> vi;
            if (i >= 2) vi.push_back(vgcd[i - 2]);
            vi.push_back(gcd(v[i - 1], v[i + 1]));
            if (i < N - 2) vi.push_back(vgcd[i + 1]);
            auto vi2 = vi;
            sort(all(vi2));
            if (vi == vi2) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}