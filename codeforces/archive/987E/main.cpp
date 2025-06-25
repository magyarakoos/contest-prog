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
            int j = i, len = 0;
            while (!vis[j]) {
                vis[j] = 1;
                j = p[j];
                len++;
            }
            result += len - 1;
        }
    }
    cout << result << "\n";
}
