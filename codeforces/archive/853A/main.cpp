#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

struct Cmp {
    bool operator()(array<int, 2> a, array<int, 2> b) {
        if ((a[1] >= t && b[1] >= t) || (a[1] < t && b[1] < t)) {
            return a[0] < b[0];
        }
        return a[1] < t;
    }
};

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	priority_queue<array<int, 2>, vector<array<int, 2>>, Cmp> pq;

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
        if (i >= tr)
		pq.pop();
		result += (t - i) * c;
        timeS[i - 1] = t;
		t++;
	}

	cout << result << '\n';
	for (int time : timeS) cout << time << ' ';
	cout << '\n';
}
