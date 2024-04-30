#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int& x : p) { 
        cin >> x;
        x--; 
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (p[i] == j && p[j] == i) {
                cout << "2\n";
                return;
            }
        }
    }
    cout << "3\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
