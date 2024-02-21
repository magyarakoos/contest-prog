#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using edge = struct { int node; int w; };

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<edge>> g(2 * N + 2);

    for (int i = 1; i <= N; i++) {
        int U, V;
        cin >> U >> V;

        g[i].push_back({U, 1});
        g[i].push_back({V, -1});
    }

    vector<int> distS(2 * N + 2, )
}