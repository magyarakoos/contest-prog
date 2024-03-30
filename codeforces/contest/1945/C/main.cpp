#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

ifstream fin("../input");

#ifdef LOCAL
#define cin fin
#endif

void solve() {
    int N;
    cin >> N;
    vector<bool> v(N);
    int zc = 0, oc = 0;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '1') {
            oc++;
            v[i] = 1;
        } else {
            zc++;
        }
    }
    
    int lzc = 0, loc = 0;
    for (int i = 0; i <= N; i++) {
        
    }
}

int main() {
    #ifndef LOCAl
    cin.tie(0);
    ios::sync_with_stdio(0);
    #endif
    int T;
    cin >> T;
    while (T--) solve();
}
