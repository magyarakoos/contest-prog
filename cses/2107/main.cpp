#include <bits/stdc++.h>
using namespace std;

vector<int> z(const string& s) {
    int n = s.size();
    vector<int> z(n), pi(n);
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (i + j < n && s[i + j] == s[j]) j++;
    }
    return z;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
}
