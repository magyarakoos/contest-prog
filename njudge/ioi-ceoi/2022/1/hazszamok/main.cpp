#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXW = 12;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int K;
    cin >> K;
    vector<int> a(K);
    for (int& x : a) cin >> x;

    vector<int> pw(MAXW + 1, 1);
    for (int i = 1; i <= MAXW; i++) pw[i] = pw[i - 1] * K;

    auto f = [&](int n) -> bool {
        vector<int> req(K);
        for (int i = 1; i <= MAXW; i++) {
            int div = (n - (pw[i - 1] - 1)) / pw[i],
                rem = max((int)0, n - (pw[i - 1] - 1)) %
                      pw[i];

            for (int j = 0; j < K; j++) {
                req[j] += div * pw[i - 1];
                req[j] += min(rem, pw[i - 1]);
                /*if (req[j] > a[j]) return 0;*/
                rem -= min(rem, pw[i - 1]);
            }
        }
        return 1;
    };

    cout << f(4) << "\n";

    /*int l = 0, r = 1e18;*/
    /*while (r - l > 1) {*/
    /*    int m = (r + l) / 2;*/
    /*    if (f(m)) {*/
    /*        r = m;*/
    /*    } else {*/
    /*        l = m;*/
    /*    }*/
    /*}*/
}
