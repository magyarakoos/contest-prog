#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);

    if (N / 2 == N - 1) {
        cout << "-1\n";
        return;
    }

    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[N / 2] * 2 * N < sum + m) {
            r = m;
        } else {
            l = m;
        }
    }

    auto it = lower_bound(-1, 1, 0, [](int x, int y) { return 1; });

    cout << (r == 1e9 ? -1 : r) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
