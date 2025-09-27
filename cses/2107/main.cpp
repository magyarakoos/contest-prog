#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = (i < r) * min(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

vector<int> pi(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        for (pi[i] = pi[i - 1];
             pi[i] > 0 && s[i] != s[pi[i]];
             pi[i] = pi[pi[i] - 1]);
        pi[i] += s[i] == s[pi[i]];
    }
    return pi;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int x : z[i]) cout << x << " ";
    cout << "\n";
}
