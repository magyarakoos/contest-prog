#include <bits/stdc++.h>

#pragma region Utility

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

int main() {
    #ifdef ONLINE_JUDGE
    speed;
    #else
    #define cin fin
    ifstream fin("input.txt");
    #endif

    int N;
    cin >> N;

    vector<vector<ll>> g(N + 1, vector<ll>(N + 1, 1e18));
    
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
        g[u][u] = g[v][v] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                smin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    ll mn = 1e18;
    vector<ll> values(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            smax(values[i], g[i][j]);
        }
        smin(mn, values[i]);
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (values[i] == mn) {
            result.push_back(i);
        }
    }

    cout << mn << '\n' << size(result) << '\n';
    for (int x : result) cout << x << ' ';
}