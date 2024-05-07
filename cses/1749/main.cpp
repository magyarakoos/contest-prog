#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5;

int t[4 * MAXN + 1], N;

void build(int curr, int tl, int tr) {
	if (tl == tr) {
		t[curr] = 1;
	} else {
		int tm = (tl + tr) / 2;
		build(curr * 2, tl, tm);
		build(curr * 2 + 1, tm + 1, tr);
		t[curr] = t[curr * 2] + t[curr * 2 + 1];
	}
}

void update(int curr, int tl, int tr, int pos) {
	if (tl == tr) {
		t[curr] = 0;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(curr * 2, tl, tm, pos);
		} else {
			update(curr * 2 + 1, tm + 1, tr, pos);
		}
        t[curr] = t[curr * 2] + t[curr * 2 + 1];
	}
}

int query(int curr, int tl, int tr, int k) {
	if (tl == tr) return tl;
    
    int tm = (tl + tr) / 2;

    if (k <= t[curr * 2]) {
        return query(curr * 2, tl, tm, k);
    } else {
        return query(curr * 2 + 1, tm + 1, tr, k - t[curr * 2]);
    }
}

int dot_query(int curr, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return dot_query(curr * 2, tl, tm, pos);
    } else {
        return dot_query(curr * 2 + 1, tm + 1, tr, pos);
    }
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

	cin >> N;

	vector<int> v(N);
	for (int& x : v) cin >> x;

    build(1, 0, N - 1);

	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
        int q = query(1, 0, N - 1, P);
        cout << v[q] << " ";
        update(1, 0, N - 1, q);
	}

	cout << "\n";
}
