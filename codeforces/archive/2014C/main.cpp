#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    int mx = a.back();

    int rp = a[N / 2];

    int l = -1, r = 1e9;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
