#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

ifstream f("../input");

#ifdef LOCAL
#define cin f
#endif

bool pal(ll x) {
    string s = to_string(x);
    int l = 0, r = size(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main() {
    ll N;
    cin >> N;
    ll x = round(cbrt(N));
    // x_max = 1e6
    for(;x;x--) {
        ll cube = x * x * x;
        if (cube <= N && pal(cube)) {
            cout << cube;
            exit(0);
        }
    }
    cout << 1;
}