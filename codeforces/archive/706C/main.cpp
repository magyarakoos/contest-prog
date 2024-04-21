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
    vector<int> costS(N);
    for (int& x : costS) cin >> x;

    int maxl = 0;
    vector<vector<pair<string, int>>> groupS;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (maxl < size(s)) {
            maxl = size(s);
            groupS.push_back({{s, costS[i]}});
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

        vector<ll> dp(size(v), INF);
        dp[0] = 0;

        for (int i = 1; i < size(v); i++) {
            if (v[i - 1].first <= v[i].first) {
                dp[i] = dp[i - 1];
            } else {
                if (v[i].second <= v[i - 1].second) }
                
                reverse(v[i].first.begin(), v[i].first.end());
                dp[i] = dp[i - 1] + v[i].second;
            }
        }

        result += dp[size(v) - 1];
    }

    cout << result << "\n";
}