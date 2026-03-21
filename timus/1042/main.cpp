#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bitset<4>> a(n);
    for (int i = 0, x; i < n; i++) {
        while (cin >> x && x != -1) { a[i][x - 1] = 1; }
    }
    for (int i = 0; i < n; i++) { cout << a[i] << "\n"; }
}
