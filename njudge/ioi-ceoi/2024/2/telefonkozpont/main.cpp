#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5;

int t[4 * MAXN + 1], lazy[4 * MAXN + 1];

void push(int curr) {
    t[curr * 2] += lazy[curr];
    t[curr * 2 + 1] += lazy[curr];
    lazy[curr * 2] += lazy[curr];
    lazy[curr * 2 + 1] += lazy[curr];
    lazy[curr] = 0;
}

void update(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) {
        return;
    }
    if (tr == tl) {
        t[curr]++;
        lazy[curr]++;
    } else {
        push(curr);
        int tmid = (tl + tr) / 2;
        update(curr * 2, tl, tmid, l, min())
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int M, N, Q;
    cin >> M >> N >> Q;

    while (N--) {
        int B, E;
        cin >> B >> E;
        
    }
}