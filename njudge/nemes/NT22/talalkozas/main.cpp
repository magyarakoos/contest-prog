#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

#define speed cin.tie(0); ios::sync_with_stdio(0)

const int INF = 100'001;

int main()
{
	speed;

	int N, H;
	cin >> N;

	H = N / 2 + (N & 1);
	
	vector<int> eS(N);
	vector<int> vS(N);

	for (int i = 0; i < N; i++) {
		int E, V;
		cin >> E >> V;
		eS[i] = E;
		vS[i] = V;
	}

	std::sort(eS.begin(), eS.end());
	std::sort(vS.begin(), vS.end());

	array<int, 2> min_v{ 0, INF };

	for (int i = 0; i < N; i++) {

		int e = vS[i],
			v = eS.back(),
			curr = N - i + 1,
			j = N;

		while (e < v && H < curr) {

			v = eS[--j];
			
			curr--;

			if (v - e < min_v[1] - min_v[0]) {
				min_v = { e, v };
			}
		}
	}

    // time limit bruh
	cout << min_v[1] - min_v[0] + 1 << '\n' << min_v[0] << ' ' << min_v[1];
}
