#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(int n, int k) {}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0 || k >= 2 * n) {
        cout << "-1\n";
    } else {

        solve(n, k);
    }
}
