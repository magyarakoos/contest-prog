#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h, s;
    while (cin >> w >> h >> s) {
        int n = w * h;
        vector<int> p(n + 5);
        iota(p.begin(), p.end(), 0);
        while (s--) {
            int u, v;
            cin >> u >> v;
            p[u - 1] = v - 1;
        }
        for (int i = 0; i < n; i++) {
            while (p[i] != p[p[i]]) p[i] = p[p[i]];
        }
        for (int i = n; i < n + 5; i++) {
            p[i] = p[n - (i - n + 2)];
        }
        // for (int i = 0; i < n + 5; i++)
        //     cout << p[i] + 1 << " ";
        // cout << "\n";

        vector a(n, vector<double>(n + 1));
        for (int i = 0; i < n - 1; i++) {
            a[i][i] = a[i][n] = 6;
            for (int j = 1; j <= 6; j++) {
                a[i][p[i + j]]--;
            }
            int x = a[i][i];
            for (int j = 0; j <= n; j++) a[i][j] /= x;
        }
        a[n - 1][n - 1] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {}
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(2) << a[i][j] << " ";
            }
            cout << "| " << a[i][n];
            cout << "\n";
        }
        cout << "\n";
    }
}
