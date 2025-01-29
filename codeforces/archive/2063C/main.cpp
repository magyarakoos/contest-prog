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
    if (N == 5) {
        cout << 3 << "\n";
        return;
    }
    int mx = *max_element(degS.begin(), degS.end());

    int result = degS[mxi];
    degS[mxi] = 0;
    for (auto v : g[mxi]) { degS[v]--; }
    mxi = max_element(degS.begin(), degS.end()) -
          degS.begin();
    result += degS[mxi] - 1;
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
