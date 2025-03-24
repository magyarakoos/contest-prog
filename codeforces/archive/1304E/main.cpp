#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

vector<int> path, first, depth;
vector<vector<int>> g;

int cmb(int a, int b) {
    return b == INF || depth[a] < depth[b] ? a : b;
}

struct Node {

    int value;
    int tl, tr;
    std::unique_ptr<Node> cl, cr;

    Node(int _value, int pos)
        : value(_value), tl(pos), tr(pos), cl(nullptr),
          cr(nullptr) {}

    Node(int _l, int _r, std::unique_ptr<Node> _cl,
         std::unique_ptr<Node> _cr)
        : tl(_l), tr(_r), cl(std::move(_cl)),
          cr(std::move(_cr)) {
        value = cmb(cl->value, cr->value);
    }

    int query(int l, int r) {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r) return value;
        if (cl && cr) {
            return cmb(cl->query(l, r), cr->query(l, r));
        } else if (cl) {
            return cl->value;
        } else {
            return cr->value;
        }
    }

    void update(int pos, int x) {
        if (tl == tr) {
            value = x;
            return;
        }
        (pos <= cl->tr ? cl : cr)->update(pos, x);
        value = cmb(cl->value, cr->value);
    }

    static std::unique_ptr<Node>
    build(const std::vector<int>& a, int l, int r) {
        if (l == r) {
            return std::make_unique<Node>(a[l], l);
        }
        int m = (l + r) / 2;
        return std::make_unique<Node>(l, r, build(a, l, m),
                                      build(a, m + 1, r));
    }
};

void dfs(int u, int p) {
    first[u] = path.size();
    path.push_back(u);
    for (int v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    path.push_back(u);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    g.resize(N + 1);
    first.resize(N + 1);
    depth.resize(N + 1);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    auto st = Node::build(path, 0, path.size() - 1);

    auto lca = [&](int u, int v) {
        return st->query(first[u], first[v]);
    };
    auto dist = [&](int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    };

    cout << st->tl << " " << st->tr << "\n";
    cout << dist(2, 5) << "\n";

    /*    int Q;
        cin >> Q;
        while (Q--) {
            int x, y, a, b, k;
            cin >> x >> y >> a >> b >> k;
            auto distS = {
                dist(a, b),
                dist(a, x) + dist(b, y) + 1,
                dist(b, x) + dist(a, y) + 1};
            for (int d : distS) {
                if (d % 2 == k % 2 && d <= k) {
                    cout << "YES\n";
                    goto next;
                }
            }
            cout << "NO\n";
            next:continue;
        }*/
}

