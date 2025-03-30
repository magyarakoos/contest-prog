#include <bits/stdc++.h>
using namespace std;

int n, a[1 << 19], b[1 << 19];

bool solve(int ans) {
    int m = 1 << ans;
    vector<vector<int>> g(m);
    vector<int> deg(m);
    for (int i = 0; i < n; i++) {
        int u = a[i] & (m - 1), v = b[i] & (m - 1);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 20; i >= 0; i--) solve(i);
}
