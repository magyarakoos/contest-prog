#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    map<int, vector<pair<string, int>>> mp;
    set<int> xS;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        xS.insert(x);
        mp[x].push_back({s, i});
    }
    while (q--) {
        int x;
        cin >> x;
        if (mp.contains(x)) {
            for (auto p : mp[x]) { cout << p.first << " "; }
            cout << "\n";
        } else {
            if (*xS.rbegin() == x) {
                auto it = xS.rbegin();
                it--;
                cout << mp[*it][0].first << "\n";
            } else if (*xS.begin() == x) {
                auto it = xS.begin();
                it++;
                cout << mp[*it][0].first << "\n";
            } else {
                auto it = xS.upper_bound(x);
                auto it2 = it;
                it2--;
                auto p1 = mp[*it][0];
                auto p2 = mp[*it2][0];
            }
        }
    }
}
