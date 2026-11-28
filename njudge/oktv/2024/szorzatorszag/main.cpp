#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int start = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == 0) {
            find_intv(start, i);
            start = i + 1;
        }
    }
}
