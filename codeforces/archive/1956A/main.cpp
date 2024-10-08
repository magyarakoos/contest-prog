#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

void solve() {
    int K, Q;
    cin >> K >> Q;
    vector<int> A(K);
    for (int& x : A) cin >> x;
    while (Q--) {
        int N;
        cin >> N;
        cout << min(N, A[0] - 1) << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
