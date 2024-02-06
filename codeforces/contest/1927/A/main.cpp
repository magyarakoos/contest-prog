#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    int first = 1e9, last = 0;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            if (i < first) {
                first = i;
            }
            if (i > last) {
                last = i;
            }
        }
    }
    cout << last - first + 1 << '\n';
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