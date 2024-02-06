#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N), b(M);
    cinv(a);
    cinv(b);

    vector<array<bool, 2>> has(K + 1);

    for (int x : a) has[x][0] = 1;
    for (int x : b) has[x][1] = 1;

    int ac = 0, bc = 0, bothc = 0;

    for (int i = 1; i <= K; i++) {
        if (has[i][0] && has[i][1]) {
            bothc++;
        }
        else if (!has[i][0] && !has[i][1]) {
            cout << "NO\n";
            return;
        }
        else if (!has[i][1]) {
            ac++;
        }
        else {
            bc++;
        }
    }
    cout << (min(ac, K / 2) + min(bc, K / 2) + bothc >= K ? "YES\n" : "NO\n");
}

int main() {
    #ifndef LOCAL
    cin.tie(0), ios::sync_with_stdio(0);
    #else
    ifstream fin("../input");
    #define cin fin
    #endif
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}