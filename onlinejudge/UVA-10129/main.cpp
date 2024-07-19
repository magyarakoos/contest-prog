#include <array>
#include <iostream>
#include <vector>

using namespace std;

array<int, 26> in, out;
array<vector<int>, 26> g;
int st, en, len;

bool has_tour() {
    for (int u = 0; u < 26; u++) {
        if (in[u] + 1 == out[u]) {
            if (st != -1) return 0;
            st = u;
        } else if (in[u] == out[u] + 1) {
            if (en != -1) return 0;
            en = u;
        } else if (in[u] != out[u]) {
            return 0;
        }
    }
    return 1;
}

void dfs(int u) {
    while (out[u]) {
        dfs(g[u][--out[u]]);
    }
    len++;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int u = s[0] - 'a', v = s.back() - 'a';
        out[u]++;
        in[v]++;
        g[u].push_back(v);
    }

    if (has_tour() && (dfs(st), len == N + 1)) {
        cout << "Ordering is possible.\n";
    } else {
        cout << "The door cannot be opened.\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        in.fill(0);
        out.fill(0);
        g.fill(vector<int>());
        len = 0;
        st = en = -1;
        solve();
    }
}
