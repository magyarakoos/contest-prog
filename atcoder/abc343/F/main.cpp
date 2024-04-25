#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

constexpr int MAXN = 2e5, INF = 2e9;

struct Vertex {
    int mx;
    int occur;
    int smx;
    int soccur;
    Vertex() : mx(-1), occur(0) {}
    Vertex(int m, int o) : mx(m), occur(o) {}
    Vertex(Vertex a, Vertex b) {
        if (a.mx < b.mx) {
        }
        else if (b.mx < a.mx) {
        }
        else {
            mx = a.mx;
            occur = a.occur;
            if (b.sm)
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
    if (pos <= tmid) {
        update(curr * 2, tl, tmid, pos, x);
    } else {
        update(curr * 2 + 1, tmid + 1, tr, pos, x);
    }
    t[curr] = {t[curr * 2], t[curr * 2 + 1]};
}

Vertex query(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) {
        return {-INF, 0};
    }

    if (tl == l && tr == r) {
        return t[curr];
    }

    int tmid = (tl + tr) / 2;
    return {
        query(curr * 2, tl, tmid, l, min(tmid, r)),
        query(curr * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r)
    };
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& e : A) cin >> e;

    build(A, 1, 0, N - 1);

    while (Q--) {
        char type;
        cin >> type;
        if (type == '1') {
            int P, X;
            cin >> P >> X;
            update(1, 0, N - 1, P - 1, X);
        } else {
            int L, R;
            cin >> L >> R;
            Vertex q = query(1, 0, N - 1, L - 1, R - 1);
            cout << q.mx << " " << q.occur << " " << q.smx << " " << q.soccur << "\n";
        }
    }
}