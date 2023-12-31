#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;

int main() {
    speed;

    int N, K, M, C, result = 0;
    cin >> N >> K >> M >> C;
    vector<vector<int>> agentS(N, vector<int>({0}));
    while (C--) {
        int T, min_gap = K, min_i = -1;
        cin >> T;
        for (int i = 0; i < N; i++) {
            int gap = T - agentS[i].back();
            if (0 < gap && gap < min_gap) {
                min_gap = gap;
                min_i = i;
            }
        }

        if (min_i != -1) {
            result++;
            agentS[min_i].push_back(T + M - 1);
        }
    }

    cout << result;
}
