#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

struct Cmp {

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
		vector<array<int, 2>> later;

		while (!pq.empty()) {
			auto [c, i] = pq.top();
			pq.pop();
		
			if (t < i) {
				later.push_back({c, i});
			} else {
				while (!later.empty()) {
					pq.push(later.back());
					later.pop_back();
				}

				result += (t - i) * c;
				timeS[i - 1] = t;

				break;
			}
		}
		t++;
	}

	cout << result << '\n';
	for (int time : timeS) cout << time << ' ';
	cout << '\n';
}