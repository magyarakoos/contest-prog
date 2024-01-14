#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)
using namespace std;

int main() {
    speed;

    int N, H;
    cin >> N >> H;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 1; i <= N; i++) {
        int k, v;
        cin >> k >> v;
        pq.push({ v, k, i });
    }

    array<vector<array<int, 2>>, 2> workS;
    workS[0].push_back({ 0, 0 });
    workS[1].push_back({ 0, 0 });

    while (!pq.empty()) {
        auto [v, k, id] = pq.top(); pq.pop();
        int mn = 1e9, mni = -1;

        for (int i = 0; i < 2; i++) {
            int gap = k - workS[i].back()[0];
            if (0 < gap && gap < mn) {
                mn = gap;
                mni = i;
            }
        }

        if (mni != -1) {
            workS[mni].push_back({ v, id });
        }
    }

    cout << workS[0].size() - 1 << ' ' << workS[1].size() - 1 << '\n';

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < workS[i].size(); j++) {
            cout << workS[i][j][1] << ' ';
        }
        cout << '\n';
    }
}
