#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    map<int, vector<pair<string, int>>> mp;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        mp[x].push_back({s, i});
    }
}
