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

const int MOD = 32609;

int N;
vector<vector<int>> g;
vector<int> trafficS, parentS, weightS;

void dp_dfs(int s) {
    trafficS[s] = 1;
    for (int e : g[s]) {
        if (e == parentS[s]) {
            continue;
        }
        parentS[e] = s;
        dp_dfs(e);
        trafficS[s] += trafficS[e];
    }
}

int main() {
    speed;

    cin >> N;

    g.resize(N + 1);
    trafficS.resize(N + 1);
    parentS.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    weightS.resize(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> weightS[i];
    }

    dp_dfs(1);

    vector<array<ll, 3>> mappingS;

    for (int i = 2; i <= N; i++) {
        mappingS.push_back({
            2 * trafficS[i] * (N - trafficS[i]), // can go through both ways
            parentS[i],
            i
        });
    }

    sort(all(weightS));
    sort(all(mappingS));

    ll result = 0;
    for (int i = 0; i < N - 1; i++) {
        result += mappingS[i][0] * weightS[i];
        result %= MOD;
    }

    cout << result << '\n';
    for (int i = 0; i < N - 1; i++) {
        cout << mappingS[i][1] << ' ' << mappingS[i][2] << ' ' << weightS[i] << '\n';
    }
}
