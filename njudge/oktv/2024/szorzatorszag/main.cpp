#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto find_intv = [&](int l, int r) {

    };
    int start = -1;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == 0 && start != -1) {
            find_intv(start, i);
            start = -1;
        } else if (a[i] != 0 && start == -1) {
            start = i;
        }
    }
}
