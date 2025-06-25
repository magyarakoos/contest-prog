#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& x : p) cin >> x, x--;
    vector<bool> vis(n);
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int j = p[i], len = 0;
            vis[i] = 1;
            while (!vis[j]) {
                j = p[j];
                len++;
            }
            result += len;
        }
    }
    cout << result << "\n";
}
