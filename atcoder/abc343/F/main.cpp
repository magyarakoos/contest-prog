#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

constexpr int MAXN = 2e5;

struct Vertex {
    int mx;
    int occur;
    Vertex(int m, int o) : mx(m), occur(o) {}
    Vertex(Vertex a, Vertex b) {
        if (a.mx < b.mx) {
            mx = b.mx;
            occur = b.occur;
        }
        else if (b.mx < a.mx) {
            mx = a.mx;
            occur = a.occur;
        }
        else {
            mx = a.mx;
            occur = a.occur + b.occur;
        }
    }
};

Vertex t[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = {v[tl], 1};
        return;
    }

    int tmid = (tl + tr) / 2;
    build(v, curr * 2, tl, tmid);
    build(v, curr * 2+  1, tmid + 1, tr);
    t[curr] = {t[curr * 2], t[curr * 2 + 1]};
}

void update(int curr, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[curr] = {x, 1};
        return;
    }

    int tmid = (tl + tr) / 2;
    update(curr * 2, tl, tmid, pos, x);
    
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& e : A) cin >> e;


    while (Q--) {
        char type;
        cin >> type;
        if (type == '1') {
            int P, X;
            cin >> P >> X;
        } else {
            int L, R;
            cin >> L >> R;
        }
    }
}