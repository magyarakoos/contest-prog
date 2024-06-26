#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 3e5;

array<ll, 2> t[4 * MAXN + 1];

array<ll, 2> max(array<ll, 2> a, array<ll, 2> b) {
	if (a[0] >= b[0]) {
		return a;
	} else {
		return b;
	}
}

void build(const vector<int>& v, int curr, int tl, int tr) {
	if (tl == tr) {
		t[curr] = {v[tl], tl};
	} else {
		int tmid = (tl + tr) / 2;
		build(v, curr * 2, tl, tmid);
		build(v, curr * 2 + 1, tmid + 1, tr);

		t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
	}
}

array<ll, 2> query(int curr, int tl, int tr, int l, int r) {
	if (l > r || tl > tr) {
		return {-1, -1};
	}
	if (l == tl && r == tr) {
		return t[curr];
	}

	int tmid = (tl + tr) / 2;
	
	return max(
		query(curr * 2, tl, tmid, l, min(tmid, r)),
		query(curr * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r)
	);
}

void update(int curr, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[curr][0] = x;
	} else {
		int tmid = (tl + tr) / 2;

		if (pos <= tmid) {
			update(curr * 2, tl, tmid, pos, x);
		} else {
			update(curr * 2 + 1, tmid + 1, tr, pos, x);
		}

		t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
	}
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int& x : v) cin >> x;

	build(v, 1, 0, N - 1);

	ll t = K, flights_left = N, result = 0;
	vector<int> timeS(N);

	while (flights_left--) {
		auto [c, i] = query(1, 0, N - 1, 0, min(t, N - 1));
		update(1, 0, N - 1, i, -1);
		result += (t - i) * c;
		timeS[i] = t++;
	}

	cout << result << "\n";
	for (int x : timeS) cout << x + 1 << " ";
	cout << "\n";
}
