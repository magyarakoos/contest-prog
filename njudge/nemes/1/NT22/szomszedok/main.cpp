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

    unordered_map<int, vector<int>> befS, aftS;
    befS[INF].push_back(0);
    aftS[0].push_back(0);

    for (int i = 0; i < M - 1; i++) {
        if (v[i] > v[M] && v[i] <= befS[INF][0]) {
            befS.back() = {v[i], i};
        }
        else if (v[i] < v[M] && v[i] >= aftS.back()[0]) {
            aftS.back() = {v[i], i};
        }
    }

    for (int i = M + 1; i < N; i++) {
        if (v[i] > v[M] && v[i] <= befS.back()[0]) {
            befS.push_back({v[i], i});
        }
        else if (v[i] < v[M] && v[i] >= aftS.back()[0]) {
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
}
