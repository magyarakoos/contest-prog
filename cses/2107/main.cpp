#include <bits/stdc++.h>
using namespace std;

vector<int> z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int j = 0;
        // if (j < r) { j = min(j - l, z[l - j]); }

        if (i + 1 < r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
}
