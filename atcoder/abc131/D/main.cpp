#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i][1] >> a[i][0];
    sort(a.begin(), a.end());
    ll ps = 0;
    for (int i = 0; i < N; i++) {
        ps += a[i][1];
        if (ps > a[i][0]) {
            cout << "No\n";
            exit(0);
        }
    }
    cout << "Yes\n";
}
