#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto neg_count = [&](int l, int r) {
        int result = 0;
        for (int i = l; i <= r; i++) { result += a[i] < 0; }
        return result;
    };
    auto two_count = [&](int l, int r) {
        int result = 0;
        for (int i = l; i <= r; i++) {
            result += abs(a[i]) == 2;
        }
        return result;
    };

    int result = -1e18, res_l = 0, res_r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > result) {
            result = a[i];
            res_l = i;
            res_r = i;
        }
    }
    auto find_intv = [&](int l, int r) {
        if (neg_count(l, r) % 2 == 0) {
            int twos = two_count(l, r);
            if (twos > result) {
                result = twos;
                res_l = l;
                res_r = r;
            }
            return;
        }

        int nl = 0;
        for (int i = l; i <= r; i++) {
            if (a[i] < 0) {
                nl = i + 1;
                break;
            }
        }
        int nr = 0;
        for (int i = r; i >= l; i--) {
            if (a[i] < 0) {
                nr = i - 1;
                break;
            }
        }
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
