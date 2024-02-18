#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N;
vector<vector<int>> g;
vector<vector<int>> pick;

int solve(int u, bool choose) {
    if (g[u].empty()) {
        return choose;
    }

    if (choose) {
        int result = 1;
        for (int child : g[u]) {
            result += solve(child, 0);
        }
        return result;
    } else {
        int result = 0;
        for (int child : g[u]) {
            int a = solve(child, 1);
            int b = solve(child, 0);
            if (a > b) {
                pick[u].push_back(child);
            }
            result += max(solve(child, 1), solve(child, 0));
        }
        return result;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    g.resize(N + 1);
    pick.resize(N + 1);

    for (int U = 2; U <= N; U++) {
        int V;
        cin >> V;
        g[V].push_back(U);
    }

    int a = solve(1, 1);
    int b = solve(1, 0);

    cout << max(a, b) << '\n';
    
    vector<int> result;

    if (a < b) {
        for (int child : pick[1]) {

        }
    }
}