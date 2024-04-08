#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5;


int N, a[MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        a[tl] = v[tl];
        return;
    }

    int tmid = (tl + tr) / 2;
    build(v, curr * 2, tl, tr);
    build(v, curr * 2 + 1, tl, tr);
    a[curr] = min(a[curr * 2], a[curr * 2] + 1);
}

int min(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return MAXN;
    }
    if (l == tl && r == tr) {
        return a[curr];
    }

    int tmid = (l + r) / 2;
    return min(
        min(curr * 2, tl, tmid, l, min(r, tmid)),
        
    );
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int& x : v) cin >> x;


}