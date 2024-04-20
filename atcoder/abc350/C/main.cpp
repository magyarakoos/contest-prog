#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N;
    cin >> N;
    map<int, int> m;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        m[A[i]] = i;
    }
    vector<array<int, 2>> result;
    for (int i = 0; i < N; i++) {
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}