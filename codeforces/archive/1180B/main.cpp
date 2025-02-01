#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) {
        cin >> x;
        if (x >= 0) { x = -x - 1; }
    }
    if (N % 2 == 1) {
        int i = min_element(a.begin(), a.end()) - a.begin();
        a[i] = -a[i] - 1;
    }
    for (int x : a) cout << x << " ";
    cout << "\n";
}
