#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    M--;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    vector<array<int, 2>> befS({{0, 0}}), aftS({{0, 0}});

    for (int i = 0; i < M; i++) {
        if (v[i] > v[M] && v[i] > befS.back()[0]) {
            befS.back() = {v[i], i};
        }
    }

    for (int i = 0; i < N; i++) {
        if (v[i] > v[M]) {
            befS.push_back(i);
        }
        else if (v[i] < v[M]) {
            aftS.push_back(i);
        }
    }


}
