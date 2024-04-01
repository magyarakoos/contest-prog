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

    vector<array<int, 2>> befS({{INF, -1}}), aftS({{-INF, -1}});

    for (int i = 0; i < M; i++) {
        if (v[i] > v[M] && v[i] < befS.back()[0]) {
            befS.back() = {v[i], i};
        }
        else if (v[i] < v[M] && v[i] > aftS.back()[0]) {
            aftS.back() = {v[i], i};
        }
    }

    for (int i = M + 1; i < N; i++) {
        if (v[i] > v[M] && v[i] < befS.back()[0]) {
            befS.push_back({v[i], i});
        }
        else if (v[i] < v[M] && v[i] > aftS.back()[0]) {
            aftS.push_back({v[i], i});
        }
    }

    befS.push_back({INF, N - 1});
    aftS.push_back({INF, N - 1});

    for (auto [score, id] : befS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";
    for (auto [score, id] : aftS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";

    int p1 = -1;
    for (int i = 0; i < size(befS) - 1; i++) {
        if (befS[i][0] == INF) continue;
        p1 = max(p1, befS[i + 1][1] - max(befS[i][1], M));
    }
    cout << p1 << "\n";

    int p2 = -1;
    for (int i = 0; i < size(aftS))
}
