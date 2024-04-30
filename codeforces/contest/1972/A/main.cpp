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
    vector<int> A(N), B(N);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    int a = 0, b = 0, res = 0;
    while (b < N) {
        if (A[a] <= B[b]) {
            a++; b++;
        } else {
            res++;
            b++;
        }
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
