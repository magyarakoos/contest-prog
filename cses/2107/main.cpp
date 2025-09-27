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
        for (int j = pi[i - 1]; j > 0 && s[i] != s[j];
             j = pi[j - 1]);
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
}
