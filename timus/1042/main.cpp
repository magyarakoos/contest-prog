#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bitset<5>> a(n);
    for (int i = 0, x; i < n; i++) {
        while (cin >> x && x != -1) a[x - 1][i] = 1;
        a[i][n] = 1;
    }
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (a[i][j]) {
                swap(a[i], a[j]);
                cout << i << " ";
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != j && a[i][j]) a[i] ^= a[j];
        }
    }
    cout << "\n";
}
