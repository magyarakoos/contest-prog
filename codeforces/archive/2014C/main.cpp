#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    if (N == 1) {
        cout << "-1\n";
        return;
    }

    auto f = [&](int i) -> bool {};

    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
