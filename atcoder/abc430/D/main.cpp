#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    s.insert(0);
    int sum = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x < *s.begin()) {
            int d = *s.begin() - x;
            if (s.size() == 1) {
                sum += d * 2;
            } else {
                sum += d;
                int d2 = *next(s.begin()) - *s.begin();
                if (d2 > d) {
                    sum -= d2;
                    sum += d;
                }
            }
        } else if (x > *s.rbegin()) {
            int d = x - *s.rbegin();
            if (s.size() == 1) {
                sum += d * 2;
            } else {
                sum += d;
                int d2 = *s.rbegin() - *next(s.rbegin());
                if (d2 > d) {
                    sum -= d2;
                    sum += d;
                }
            }
        } else {
            auto it = s.upper_bound(x);
            int d1 = x - *prev(it), d2 = *it - x;
            sum += min(d1, d2);
            if (*prev(it) != *s.begin()) {
                int d3 = min(*prev(it) - *prev(prev(it)),
                             *it - *prev(it));
                if (d3 > d1) {
                    sum -= d3;
                    sum += d1;
                }
            } else {
                sum += d1;
                sum -= *it - *prev(it);
            }
            if (*it != *s.rbegin()) {
                int d4 =
                    min(*next(it) - *it, *it - *prev(it));
                if (d4 > d2) {
                    sum -= d4;
                    sum += d2;
                }
            } else {
                sum += d2;
                sum -= *it - *prev(it);
            }
        }
        s.insert(x);
        cout << sum << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
}
