#include <bits/stdc++.h>
using namespace std;

int N, M;
int adj[26][26];
map<int, int> cache;
map<int, vector<int>> order;

int dp(int mask) {
    if (cache.count(mask)) return cache[mask];
    if (mask == 0) return cache[mask] = 0;

    int result = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (mask >> i & 1) {
            int nmask = mask & ~(1 << i);
            int cost_a = dp(nmask), cost_b = cost_a;

            vector<int> norder = order[nmask];
            if (find(norder.begin(), norder.end(), i) ==
                norder.end()) {
                for (int j = 0; j < norder.size(); j++) {
                    cost_a += (adj[i][norder[j]] +
                               adj[norder[j]][i]) *
                              (j + 1);
                    cost_b += (adj[i][norder[j]] +
                               adj[norder[j]][i]) *
                              (norder.size() - j);
                }
                if (cost_a < cost_b) {
                    norder.insert(norder.begin(), i);
                } else {
                    norder.insert(norder.end(), i);
                }
            }

            int cost = min(cost_a, cost_b);
            if (cost < result) {
                result = cost;
                order[mask] = norder;
            }
        }
    }
    cout << bitset<3>(mask) << " " << result << " | ";
    for (int x : order[mask]) cout << x << " ";
    cout << "\n";
    return cache[mask] = result;
}

int main() {
    string s;
    cin >> N >> M >> s;
    for (int i = 1; i < N; i++) {
        adj[s[i - 1] - 'a'][s[i] - 'a']++;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp((1 << M) - 1);
}
