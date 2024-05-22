#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> t, lazy;

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v, curr * 2, tl, tm);
        build(v, curr * 2 + 1, tm + 1, tr);
        t[curr] = min(t[curr * 2], t[curr * 2 + 1]);
    }
}

void push(int curr) {
    t[curr * 2] += lazy[curr];
    lazy[curr * 2] += lazy[curr];
    t[curr * 2 + 1] += lazy[curr];
    lazy[curr * 2 + 1] += lazy[curr];
    lazy[curr] = 0;
}

void update(int curr, int tl, int tr, int l, int r, int delta) {
    if (tl > tr || l > r) return;
    if (l == tl && r == tr) {
        t[curr] += delta;
        lazy[curr] += delta;
    } else {
        push(curr);
        int tm = (tl + tr) / 2;
        update(curr * 2, tl, tm, l, min(tm, r), delta);
        update(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r, delta);
        t[curr] = min(t[curr * 2], t[curr * 2 + 1]);
    }
}

ll query(int curr, int tl, int tr, int l, int r) {
    if (tl > tr || l > r) return INF;
    if (l == tl && r == tr) {
        return t[curr];
    }
    push(curr);
    int tm = (tl + tr) / 2;
    return min(
        query(curr * 2, tl, tm, l, min(tm, r)),
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
    );
}

string read_line() {
    string s;
    getline(cin, s);
    return s;
}

vector<int> tokenize(string s) {
    stringstream ss(s);
    vector<int> res;
    while (ss >> s) {
        res.push_back(stoi(s));
    }
    return res;
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int& x : v) cin >> x;

    t.resize(4 * N + 1);
    lazy.resize(4 * N + 1);

    build(v, 1, 0, N - 1);

    int Q;
    cin >> Q;

    // itt van valamiért egy üres string
    read_line();

    while (Q--) {
        vector<int> valueS = tokenize(read_line());
        int l = valueS[0], r = valueS[1];

        if (valueS.size() == 2) {
            if (l > r) {
                cout << min(query(1, 0, N - 1, l, N - 1), query(1, 0, N - 1, 0, r)) << "\n";
            } else {
                cout << query(1, 0, N - 1, l, r) << "\n";
            }
        } else {
            int x = valueS[2];
            if (l > r) {
                update(1, 0, N - 1, l, N - 1, x);
                update(1, 0, N - 1, 0, r, x);
            } else {
                update(1, 0, N - 1, l, r, x);
            }
        }
    }
}
