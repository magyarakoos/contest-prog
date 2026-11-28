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

    int result = 0, res_l = 0, res_r = 0;
    auto find_intv = [&](int l, int r) {
        if (neg_count(l, r) % 2 == 0) {
            int twos = two_count(l, r);
            // cout << "OPT " << l << " " << r << " " <<
            // twos
            //      << "\n";
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

        int ltwos = two_count(nl, r);
        // cout << "OPT " << nl << " " << r << " " << ltwos
        //      << "\n";
        if (ltwos > result) {
            result = ltwos;
            res_l = nl;
            res_r = r;
        }
        int rtwos = two_count(l, nr);
        // cout << "OPT " << l << " " << nr << " " << rtwos
        //      << "\n";
        if (rtwos > result) {
            result = rtwos;
            res_l = l;
            res_r = nr;
        }
    };
    int start = -1;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == 0 && start != -1) {
            // cout << "EX " << start << " " << i - 1 <<
            // "\n";
            find_intv(start, i - 1);
            start = -1;
        } else if (a[i] != 0 && start == -1) {
            start = i;
        }
    }
    if (result == 0) {
        int nres = -1e18;
        for (int i = 1; i <= n; i++) {
            if (a[i] > nres) {
                nres = a[i];
                res_l = i;
                res_r = i;
            }
        }
    }
    // cout << result << "\n";
    cout << res_l << " " << res_r << "\n";
}
