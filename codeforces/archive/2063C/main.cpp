#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N;
    cin >> N;
    vector<int> degS(N + 1);
    vector<vector<int>> g(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        degS[U]++;
        degS[V]++;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    int mx = *max_element(degS.begin(), degS.end());
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (degS[i] == mx) {
            for (auto v : g[i]) { degS[v]--; }
            degS[i] = 0;
            result =
                max(result, mx +
                                *max_element(degS.begin(),
                                             degS.end()) -
                                1);
            degS[i] = mx;
            for (auto v : g[i]) { degS[v]++; }
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
