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
        for (int i = 0; i < L - 1; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            // cout << x << " ";
        }
        // cout << " | ";
        for (int i = 0; i < R - L + 1; i++) {
            int x;
            cin >> x;
            b.push_back(x);
            // cout << x << " ";
        }
        // cout << " | ";
        for (int i = R; i < N; i++) {
            int x;
            cin >> x;
            c.push_back(x);
            // cout << x << " ";
        }
        // cout << " | ";
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        sort(c.begin(), c.end());
        int curr = 0, result = 0;
        for (int i = 0;
             i < a.size() && i < b.size() && a[i] < b[i];
             i++) {
            curr += b[i] - a[i];
        }
        result = max(result, curr);
        curr = 0;

        for (int i = 0;
             i < c.size() && i < b.size() && c[i] < b[i];
             i++) {
            curr += b[i] - c[i];
        }
        cout << accumulate(b.begin(), b.end(), (int)0) -
                    max(result, curr)
             << "\n";
    }
}
