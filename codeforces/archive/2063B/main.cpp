#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N, L, R;
        cin >> N >> L >> R;
        vector<int> a, b, c;
        for (int i = 0; i < L; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < R - L + 1; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        for (int i = R; i < N; i++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        sort(c.begin(), c.end());
        for (int i = 0; i <) }
}
