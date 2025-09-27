#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    s = t + "#" + s;
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        z[i] = (i < r) * min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + 1 > r) {
            l = i;
            r = i + z[i];
        }
    }
    cout << count(z.begin(), z.end(), s.size()) << "\n";
}
