#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

constexpr int INF = 1e4 + 1;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    M--;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    vector<array<int, 2>> befS({{INF, M}}), aftS({{0, M}});

    for (int i = 0; i < M - 1; i++) {
        if (v[i] > v[M] && v[i] < befS.back()[0]) {
            befS.back() = {v[i], i};
        }
        else if (v[i] < v[M] && v[i] > aftS.back()[0]) {
            aftS.back() = {v[i], i};
        }
    }

    for (int i = M + 1; i < N; i++) {
        if (v[i] > v[M]) {
            befS.push_back({v[i], i});
        }
        else if (v[i] < v[M]) {
            aftS.push_back({v[i], i});
        }
    }

    for (auto [score, id] : befS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";
    for (auto [score, id] : aftS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";
}
