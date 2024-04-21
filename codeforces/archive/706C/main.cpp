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
            v.push_back({{s, s}});
            costS.push_back({C[i]});
        }
        else if (maxl == size(s)) {
            v.back().push_back({s, s});
            costS.back().push_back(C[i]);
        }
        else {
            cout << -1;
            exit(0);
        }
        reverse(v.back().back()[1].begin(), v.back().back()[1].end());
    }

    ll result = 0;
    N = size(v);

    for (int i = 0; i < N; i++) {

        int M = size(v[i]);
        vector<array<ll, 2>> dp(M, {INF, INF});
        dp[0] = {0, 0};

        for (int j = 1; j < M; j++) {
            if (v[i][j - 1][0] <= v[i][j][0]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            if (v[i][j - 1][1] <= v[i][j][0]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }

            if (v[i][j - 1][0] <= v[i][j][1]) {
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + costS[i][j]);
            }
            if (v[i][j - 1][1] <= v[i][j][1]) {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + costS[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            cout << "(" << dp[i][0] << "," << dp[i][1] << ") ";
        }
        cout << "\n";

        result += min(dp[M - 1][0], dp[M - 1][1]);
    }

    cout << result << "\n";
}