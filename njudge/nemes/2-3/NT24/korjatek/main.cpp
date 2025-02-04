#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 2e5;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> P(N);
    for (int& x : P) cin >> x;
    P.insert(P.end(), P.begin(), P.end());
    P.push_back(INF);

    vector<int> ng(2 * N + 1);
    ng[2 * N] = 2 * N;
    for (int i = 2 * N - 1; i >= 0; i--) {
        ng[i] = ng[i + 1];
        while (P[i] > P[ng[i]]) { ng[i] = ng[ng[i]]; }
    }
    for (int i = 0; i < 2 * N; i++) { cout << P[i] << " "; }
    cout << "\n";
    for (int i = 0; i < 2 * N; i++) {
        cout << ng[i] << " ";
    }
    cout << "\n";
}
