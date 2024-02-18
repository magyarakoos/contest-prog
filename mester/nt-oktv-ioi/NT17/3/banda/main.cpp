#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N;
vector<vector<int>> g;

int32_t solve(int u, bool choose) {

}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    g.resize(N + 1);

    for (int U = 2; U <= N; U++) {
        int V;
        cin >> V;
        g[V].push_back(U);
    }

    int a = solve(1, 1);
    int b = solve(1, 0);
}