#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int& x : a) cin >> x;
    auto st = Node::build(a, 0, N - 1);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << st->query(l - 1, r - 1) << "\n";
    }
}
