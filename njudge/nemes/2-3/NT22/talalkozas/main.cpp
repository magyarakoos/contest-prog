#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

const int INF = 100'000;

int main() {
	speed;

	int N;
	cin >> N;

	vector<int> beginS(N), endS(N);

	for (int i = 0; i < N; i++) {
		cin >> beginS[i] >> endS[i];
	}

	sort(all(beginS));
	sort(all(endS));	

	int
	H = N / 2 + (N & 1),
	curr = 0,
	begin = 0, 
	end = 0,
	mn_begin = -1,
	mn_end = -1,
	begin_i = 0,
	end_i = 0;

	for (; begin <= INF; begin++) {

		while ((end <= INF && curr < H) || begin == end) {
			while (begin_i < N && beginS[begin_i] == end) {
				begin_i++;
				curr++;
			}
			end++;
		}

		if (H <= curr && (mn_begin == -1 || end - begin < mn_end - mn_begin)) {
			mn_begin = begin;
			mn_end = end;
		}

		while (end_i < N && endS[end_i] == begin) {
			end_i++;
			curr--;
		}
	}

	cout 
	<< mn_end - mn_begin << '\n' 
	<< mn_begin << ' ' << mn_end - 1; 
}
