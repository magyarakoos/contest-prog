#include <bits/stdc++.h>
using namespace std;

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

    befS.push_back({INF, N});
    aftS.push_back({INF, N});

    for (auto [score, id] : befS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";
    for (auto [score, id] : aftS) {
        cout << score << " " << id << "\n";
    }
    cout << "\n";

    int p1 = -1, p1_i = -1;
    for (int i = 0; i < size(befS) - 1; i++) {
        if (befS[i][0] == INF) continue;
        int val = befS[i + 1][1] - max(befS[i][1], M);
        if (p1 < val) {
            p1 = val;
            p1_i = befS[i][1];
        }
    }

    if (p1 == -1) {
        cout << "-1\n";
    } else {
        cout << p1_i << " " << p1 << "\n";
    }

    int p2 = -1, p2_i = -1;
    for (int i = 0; i < size(aftS) - 1; i++) {
        if (abs(aftS[i][0]) == INF) continue;
        int val = aftS[i + 1][1] - max(aftS[i][1], M);
        if (p2 < val) {
            p2 = val;
            p2_i = aftS[i][1];
        }
    }

    if (p2 == -1) {
        cout << "-1";
    } else {
        cout << p2_i << " " << p2;
    }
}
