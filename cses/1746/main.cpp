#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    // 2 0 2
    /*
        0 0 0 0 0 0
        0 0 1 0 0 0
        0 1 1 1 0 0
        0 0 3 0 0 0
    */

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (v[i]) {

            }
        }
    }
}