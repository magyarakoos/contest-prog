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

    if (N == 1) {
        cout << "-1\n";
        return;
    }

    auto f = [&](int x) -> bool { return a[N / 2] * N < sum + x; };
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << (r == 1e9 ? -1 : r) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
