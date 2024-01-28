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

    int N;
    int K;
    cin >> N >> K;

    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<int> dp(N + 1), from(N + 1);

    dp[1] = v[1];
    from[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + v[i];
        from[i] = i;
        int mx = v[i];

        for (int j = 1; j < K && i - j > 0; j++) {
            smax(mx, v[i - j]);

            if (dp[i - j - 1] + mx < dp[i]) {
                dp[i] = dp[i - j - 1] + mx;
                from[i] = i - j;
            }
        }
    }

    cout << dp[N] << '\n';

    vector<array<int, 2>> rangeS;

    while (0 < N) {
        rangeS.push_back({from[N], N});
        N = from[N] - 1;
    }

    for (int i = size(rangeS) - 1; i >= 0; i--) {
        cout << rangeS[i][0] << ' ' << rangeS[i][1] << '\n';
    }
}