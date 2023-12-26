#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define range(start, exit, incr) for (int i = start; i exit; i incr)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, K;
    cin >> N >> K;

    vector<int> T(N + 1), H(N + 1);
    vector<point> dp(N + 1);

    int maxi = 0;
    range(1, <= N, ++) {
        cin >> T[i] >> H[i];

        int j = 1, curr_best = 0;
        while (j < i && T[i] - T[j] >= K) {
            if (dp[curr_best][0] < dp[j][0]) {
                curr_best = j;
            }
            j++;
        }

        dp[i][0] = dp[curr_best][0] + H[i];
        dp[i][1] = curr_best;

        if (dp[maxi][0] < dp[i][0]) {
            maxi = i;
        }
    }

    cout << dp[maxi][0] << '\n';

    vector<int> path;
    while (maxi > 0) {
        path.push_back(maxi);
        maxi = dp[maxi][1];
    }

    cout << path.size();

    range(path.size() - 1, >= 0, --) {
        cout << ' ' << path[i];
    }
}
