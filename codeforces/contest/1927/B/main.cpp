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
    vector<int> v(N), alpha(26);
    cinv(v);
    string s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            if (alpha[j] == v[i]) {
                alpha[j]++;
                s += (char)(j + 'a');
                break;
            }
        }
    }
    cout << s << '\n';
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
