#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int K;
    cin >> K;
    vector<int> a(K);
    for (int& x : a) cin >> x;

    vector<int> pw(18, 1);
    for (int i = 1; i < 18; i++) pw[i] = pw[i - 1] * K;

    auto f = [&](int n) -> bool {
        vector<int> req(K);
        for (int i = 1; n / pw[i - 1]; i++) {
            int div = n / pw[i], rem = n % pw[i];
            for (int j = 0; j < K; j++) {
                req[j] += div * pw[i - 1];
                req[j] += min(rem, pw[i - 1]);
                rem -= min(rem, pw[i - 1]);
            }
            req[0] -= pw[i - 1];
        }
        for (int i = 0; i < K; i++) {
            if (req[i] > a[i]) return 0;
        }
        return 1;
    };

    int l = 0, r = 1e17;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (!f(m + 1)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << "\n";
}
