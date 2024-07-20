#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1 << 16;

array<int, MAXN> in, out;
array<vector<int>, MAXN> g;
string path;
int N, st, en;

bool has_path() {
    for (int u = 0; u < MAXN; u++) {
        if (in[u] + 1 == out[u]) {
            if (st) return 0;
            st = u;
        } else if (in[u] == out[u] + 1) {
            if (en) return 0;
            en = u;
        } else if (in[u] != out[u]) {
            return 0;
        }
    }

    if (!st) {  // Eulerian circuit
        for (int u = 0; u < MAXN; u++) {
            if (out[u]) {
                st = u;
                en = u;
                break;
            }
        }
    }

    return 1;
}

void dfs(int u) {
    while (out[u]) {
        dfs(g[u][--out[u]]);
    }
    path += char(u & ((1 << 8) - 1));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char c, d, e;
        cin >> c >> d >> e;
        int u = c | (d << 8), v = d | (e << 8);

        g[u].push_back(v);
        in[v]++;
        out[u]++;
    }

    if (has_path() && (dfs(st), path.size() == N + 1)) {
        reverse(path.begin(), path.end());
        cout << "YES\n" << path + char((en & (((1 << 8) - 1) << 8)) >> 8);
    } else {
        cout << "NO\n";
    }
}
