#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

vector<int> t;

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v, curr * 2, tl, tm);
        build(v, curr * 2 + 1, tm + 1, tr);
        t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
    }
}

int query(int curr, int tl, int tr, int l, int r) {
    if (tl > tr || l > r) return -INF;
    if (l == tl && r == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    return max(
        query(curr * 2, tl, tm, l, min(tm, r)),
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
    );
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    t.resize(4 * N + 1);
    build(v, 1, 0, N - 1);

    int result = 0;

    while (M--) {
        int A, B;
        cin >> A >> B;
        result += query(1, 0, N - 1, A - 1, B - 2) == v[A - 1];
    }

    cout << result;
}
