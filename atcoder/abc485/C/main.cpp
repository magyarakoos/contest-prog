#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) { s.insert(i); }
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<vector<int>> posS(n + 1);
    for (int i = 0; i < n; i++) { posS[a[i]].push_back(i); }
    vector<int> result(n);
    for (int i = 1; i <= n; i++) {
        for (int j : posS[i]) { s.erase(j); }
        for (int j : posS[i]) {
            int mn = *s.begin();
            int mx = *s.rbegin();
            if (j < mn) {
                result[j] = mn - j;
            } else if (j > mx) {
                result[j] = j - mx;
            } else {

                auto [it, b] = s.insert(j);
                s.erase(j);
            }
        }
        for (int j : posS[i]) { s.insert(j); }
    }
}
