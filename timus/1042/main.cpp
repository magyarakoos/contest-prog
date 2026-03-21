#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bitset<5>> a(n);
    for (int i = 0, x; i < n; i++) {
        while (cin >> x && x != -1) a[i][x - 1] = 1;
        a[i][n - 1] = 1;
    }
    for (int i = 0; i < n; i++) { cout << a[i] << "\n"; }
    cout << "\n";
    for (int k = 0; k < 2; k++) {

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (a[i][j]) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i != j && a[i][j]) a[i] ^= a[j];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << "\n";
        }
    }
}
