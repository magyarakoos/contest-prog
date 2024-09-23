#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
