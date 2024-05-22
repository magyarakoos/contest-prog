#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> ps, t, lazy;

void build(int curr, int tl, int tr) {
	if (tl == tr) {
		t[curr] = ps[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(curr * 2, tl, tm);
		build(curr * 2 + 1, tm + 1, tr);
		t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
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
		int tm = (tl + tr) / 2;
		push(curr);
		update(curr * 2, tl, tm, l, min(tm, r), delta);
		update(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r, delta);
		t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
	}
}

ll query(int curr, int tl, int tr, int l, int r) {
	if (tl > tr || l > r) return -INF;
	if (l == tl && r == tr) {
		return t[curr];
	}
	push(curr);
	int tm = (tl + tr) / 2;
	return max(
		query(curr * 2, tl, tm, l, min(tm, r)),
		query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
	);
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	
	int N, Q;
	cin >> N >> Q;

	vector<ll> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	
	ps.resize(N + 1);
	t.resize(4 * N + 5);
	lazy.resize(4 * N + 5);

	partial_sum(v.begin(), v.end(), ps.begin());

	build(1, 0, N);

	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int K, U;
			cin >> K >> U;
			update(1, 0, N, K, N, U - v[K]);
			v[K] = U;
		} else {
			int A, B;
			cin >> A >> B;
			cout << max(0LL, query(1, 0, N, A, B) - query(1, 0, N, A - 1, A - 1)) << "\n";
		}
	}
}
