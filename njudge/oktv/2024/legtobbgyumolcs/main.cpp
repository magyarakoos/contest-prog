#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> a(n + 1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i + 1] = c == 'K';
    }
    vector<int> ps(n + 1), ss(n + 2);
}
