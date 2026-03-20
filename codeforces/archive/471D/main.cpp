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
    vector<int> a(n), b(w), da(n - 1), db(w - 1);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 1; i < n - 1; i++) {
        da[i - 1] = a[i] - a[i - 1];
    }
    for (int i = 1; i < w - 1; i++) {
        db[i - 1] = b[i] - b[i - 1];
    }
    db.push_back(2e9);
    db.insert(db.end(), da.begin(), da.end());
    for (int x : db) cout << x << " ";
    cout << "\n";
    auto z = z_function(db);
    int result = 0;
    for (int i = w; i < db.size(); i++) {
        result += z[i] == w - 1;
    }
    cout << result << "\n";
}
