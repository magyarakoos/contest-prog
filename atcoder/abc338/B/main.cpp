#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    for (int& x : Q) cin >> x;
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    int res = 0;
    
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}