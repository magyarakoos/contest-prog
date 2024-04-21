#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> C(N);
    for (int& x : C) cin >> x;

    int maxl = 0;
    vector<vector<array<string, 2>>> v;
    vector<vector<int>> costS;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (maxl < size(s)) {
            maxl = size(s);
            v.push_back({s, s});
            
        }
        else if (maxl == size(s)) {
            groupS.back().push_back({s, costS[i]});
        }
        else {
            cout << -1;
            exit(0);
        }
    }

    ll result = 0;

    for (auto& v : groupS) {

        N = size(v);
        vector<array<ll, 2>> dp(N, {INF, INF});
        dp[0] = {0, 0};

        for (int i = 1; i < N; i++) {

        }
    }

    cout << result << "\n";
}