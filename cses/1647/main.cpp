#include <bits/stdc++.h>
using namespace std;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

struct Node {
    const static int INF = 1e9;

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
        value = std::min(cl->value, cr->value);
    }

    int query(int l, int r) {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r) return value;
        return std::min(cl->query(l, r), cr->query(l, r));
    }

    void update(int pos, int x) {
        if (tl == tr) {
            value = x;
            return;
        }
        (pos <= cl->tr ? cl : cr)->update(pos, x);
        value = std::min(cl->value, cr->value);
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

int st[25][200005];
int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) cin >> st[0][i];
    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] = min(st[i - 1][j],
                           st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        int i = log2_floor(R - L + 1);
        cout << min(st[i][L], st[i][R - (1 << i) + 1])
             << "\n";
    }
}
