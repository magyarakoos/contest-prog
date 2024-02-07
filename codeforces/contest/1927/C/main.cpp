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

    vector<array<bool, 2>> has(K + 1);

    while (N--) {
        int a;
        cin >> a;
        if (a <= K) has[a][0] = 1;
    }
    while (M--) {
        int b;
        cin >> b;
        if (b <= K) has[b][1] = 1;
    }

    int ac = 0, bc = 0, bothc = 0;

    for (int i = 1; i <= K; i++) {
        if (!has[i][0] && !has[i][1]) {
            cout << "NO\n";
            return;
        }
        
        if (has[i][0] && has[i][1]) {
            bothc++;
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
    cin.tie(0), ios::sync_with_stdio(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
