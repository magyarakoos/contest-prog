#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.rbegin(), a.rend());
    int mx_j = -1, mn_i = -1;
    for (auto [x, i] : a) {
        if (mn_i > i) mn_i = i;
        mx_j = max(mx_j, i);
    }
    cout << (mx_j - mn_i > 0 ? mx_j - mn_i : -1);
}
