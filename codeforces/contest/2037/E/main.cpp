#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N - 1; i++) {
        cout << i + 1 << " " << N << endl;
        cin >> a[i];
    }

    vector<int> result(N);
    for (int i = N - 2; i >= 0; i--) {
        int d = a[i] - a[i + 1];
        result[i] = result[i + 1] + d;
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
