#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 3e5;

array<int, 2> t[4 * MAXN + 1];
void build(const vector<int>& v, int curr, int tl, int tr) {
	if (tl == tr) {
		t[curr] = {v[tl], tl};
	} else {
		int tmid = (tl + tr) / 2;
		build(v, curr * 2, tl, tmid);
		build(v, curr * 2 + 1, tmid + 1, tr);

		if (t[curr * 2][0] >= t[curr * 2 + 1][0]) {
			t[curr] = t[curr * 2];
		} else {
			t[curr] = t[curr * 2 + 1];
		}
	}
}

array<int, 2> query(int curr, int tl, int tr, int l, int r) {
	if (l > r) {
		return {INT_MIN, -1};
	}
	if (l == tl && r == tr) {
		return t[curr];
	}

	int tmid = (tl + tr) / 2;
	
	auto a = query(curr * 2, tl, tmid, l, min(tmid, r));
	auto b = query(curr * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r);
	
	if (a[0] >= b[0]) {
		return a;
	} else {
		return b;
	}
}

void update(int curr, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		
	}
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int C;
		cin >> C;
		pq.push({C, i + 1});
	}

	ll result = 0;
    t = K + 1;
	vector<int> timeS(N);

	while (!pq.empty()) {
        auto [c, i] = pq.top();
		pq.pop();
		result += (t - i) * c;
		timeS[i - 1] = t;
		t++;
	}

	cout << result << '\n';
	for (int time : timeS) cout << time << ' ';
	cout << '\n';
}
