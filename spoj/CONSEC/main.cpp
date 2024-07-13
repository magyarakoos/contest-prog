#include <array>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

struct DSU {
    vector<int> lnk, rnk;
    DSU(int n) : lnk(n), rnk(n, 1) { iota(lnk.begin(), lnk.end(), 0); }

    int find(int x) {
        if (x != lnk[x]) {
            x = find(lnk[x]);
        }
        return x;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rnk[y] < rnk[x]) swap(x, y);
        lnk[y] = x;
        rnk[x] += rnk[y];
    }
};

void solve() {
    string s;
    int Q, N;
    cin >> s >> Q;
    N = s.size();

    vector<array<int, 2>> queryS(Q);
    for (auto& [type, i] : queryS) {
        cin >> type >> i;
        if (type == 2) {
            type = s[i];
            s[i] = '#';
        }
    }

    DSU dsu{N};

    for (int i = 1; i < N; i++) {
        if (s[i] == '#') continue;
        if (s[i - 1] == s[i]) {
            dsu.unite(i - 1, i);
        }
    }

    stack<int> result;

    for (int i = Q - 1; i >= 0; i--) {
        auto [type, j] = queryS[i];
        if (type == 1) {
            result.push(dsu.rnk[j]);
        } else {
            char c = type;
            if (j == 0) {
                if (c == s[1]) {
                    dsu.unite(0, 1);
                }
            } else if (j == N - 1) {
                if (c == s[N - 2]) {
                    dsu.unite(N - 2, N - 1);
                }
            } else {
                if (c == s[j - 1]) {
                    dsu.unite(j - 1, j);
                }
                if (c == s[j + 1]) {
                    dsu.unite(j, j + 1);
                }
            }
        }
    }

    while (!result.empty()) {
        cout << result.top() << "\n";
        result.pop();
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}
