#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> z_function(const vector<int>& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) { z[i] = min(r - i, z[i - l]); }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
}
