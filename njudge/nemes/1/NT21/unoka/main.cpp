#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;
using u16 = unsigned short;

int main() {
    speed;

    u16 N, M;
    cin >> N >> M;

    vector<vector<u16>> g(N + 1);
    while (M--) {
        u16 U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }

    int max_n = 0, max_v = 0;

    for (int s = 1; s <= N; s++) {
        int curr = 0;
        for (int child : g[s]) {
            curr += g[child].size();
        }
        if (max_v < curr) {
            max_v = curr;
            max_n = s;
        }
    }

    if (max_v) {
        cout << max_n << ' ' << max_v;
    } else {
        cout << -1;
    }
}
