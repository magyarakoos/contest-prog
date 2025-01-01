#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXW = 17;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int K;
    cin >> K;
    vector<int> a(K);
    cin >> a[K - 1];
    for (int i = 0; i < K - 1; i++) cin >> a[i];

    vector<int> pw(MAXW + 1, 1);
    for (int i = 1; i <= MAXW; i++) pw[i] = pw[i - 1] * K;

    auto f = [&](int n) -> bool {
        vector<int> req(K);
        for (int i = 1; i <= MAXW; i++) {
            int num = max((int)0, n - (pw[i - 1] - 1));
            int div = num / pw[i], rem = num % pw[i];
            for (int j = 0; j < K; j++) {
                req[j] += div * pw[i - 1];
                req[j] += min(rem, pw[i - 1]);
                if (req[j] > a[j]) return 0;
                rem -= min(rem, pw[i - 1]);
            }
        }
        return 1;
    };

    f(4);
    /*int l = 0, r = 1e17;*/
    /*while (r - l > 1) {*/
    /*    int m = (r + l) / 2;*/
    /*    if (!f(m)) {*/
    /*        r = m;*/
    /*    } else {*/
    /*        l = m;*/
    /*    }*/
    /*}*/
    /*cout << l << "\n";*/
}
