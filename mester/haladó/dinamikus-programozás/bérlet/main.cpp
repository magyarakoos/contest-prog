#include <bits/stdc++.h>

#pragma region Utility

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

int main() {
    speed;

    int N, M;
    cin >> N >> M;

    vector<point> v(N);
    for (point& p : v) cin >> p[0] >> p[1];

    vector<pair<int, point>> dp(M, {0, {-1, -1}});
0
    for (int i = 1; i <= M; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < N; j++) {
            if (v[j][1] == i) {
                assert(v[j][0] - 1 >= 0 && v[j][0] - 1 <= M);

                if (dp[i].first < dp[v[j][0] - 1].first + 1) {
                    dp[i].first  = dp[v[j][0] - 1].first + 1;
                    dp[i].second[0] = v[j][0] - 1;
                    dp[i].second[1] = j;
                }
            }
        }
    }
/*
    cout << dp[M].second[0] << '\n' << dp[M].first << '\n';
    
    vector<int> path;
    point curr = dp[M].second;

    while (curr[0] != -1) {
        path.push_back(curr[1] + 1);
        curr = dp[curr[0]].second;
    }

    for (int x : path) cout << x << ' ';
*/
}
