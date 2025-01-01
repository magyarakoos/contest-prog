#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXW = 17;

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
            int div = n / pw[i], rem = n % pw[i];
            cout << div << " " << rem << "\n";
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
