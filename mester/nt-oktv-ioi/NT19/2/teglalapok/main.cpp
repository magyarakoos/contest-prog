#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        a[curr] = v[tl];
        return;
    }
 
    int tmid = (tl + tr) / 2;
    build(v, curr * 2, tl, tmid);
    build(v, curr * 2 + 1, tmid + 1, tr);
    a[curr] = a[curr * 2] + a[curr * 2 + 1];
}
 
ll query(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return a[curr];
    }
    
    int tmid = (tl + tr) / 2;
    return 
        query(curr * 2, tl, tmid, l, min(tmid, r)) +
        query(curr * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r)
    ;
}
 
void update(int curr, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        a[curr] = x;
        return;
    }
 
    int tmid = (tl + tr) / 2;
    
    if (pos <= tmid) {
        update(curr * 2, tl, tmid, pos, x);
    } else {
        update(curr * 2 + 1, tmid + 1, tr, pos, x);
    }
    a[curr] = a[curr * 2] + a[curr * 2 + 1];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    while (N--) {
        int P, D;
        cin >> P >> D;
        update(1, 0, H - 1, P, P + K, D);
        //cerr << endl;
    }
}