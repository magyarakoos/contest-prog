#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

const ll MAXN = 2e5, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int plus_cnt = 0, minus_cnt = 0, a_rating = 0, b_rating = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            if (a[i] == 1) plus_cnt++;
            if (a[i] == -1) minus_cnt++;
        } else if (a[i] < b[i]) {
            b_rating += b[i];
        } else {
            a_rating += a[i];
        }
    }

    while (plus_cnt--) {
        if (a_rating < b_rating) a_rating++;
        else b_rating++;
    }

    while (minus_cnt--) {
        if (a_rating < b_rating) b_rating--;
        else a_rating--;
    }

    cout << min(a_rating, b_rating) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}

