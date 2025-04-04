#include <bits/stdc++.h>
using namespace std;

int N, M;
int adj[26][26];
map<int, int> cache;
map<int, deque<int>> order;

int dp(int mask) {
    if (cache.count(mask)) return cache[mask];
    if (mask == 0) return cache[mask] = 0;

    int result = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (mask >> i & 1) {
            int nmask = mask & ~(1 << i);
            int cost_a = dp(nmask), cost_b = cost_a;

            deque<int> norder = order[nmask];
            for (int j = 0; j < norder.size(); j++) {
                cost_a += (adj[i][norder[j]] +
                           adj[norder[j]][i]) *
                          (j + 1);
                cost_b += (adj[i][norder[j]] +
                           adj[norder[j]][i]) *
                          (norder.size() - j);
            }
            if (cost_a < cost_b) {
                norder.push_front(i);
            } else {
                norder.push_back(i);
            }

            int cost = min(cost_a, cost_b);
            if (cost < result) {
                result = cost;
                order[mask] = norder;
            }
        }
    }
    return cache[mask] = result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> N >> M >> s;
    for (int i = 1; i < N; i++) {
        adj[s[i - 1] - 'a'][s[i] - 'a']++;
    }
    cout << dp((1 << M) - 1);
}
