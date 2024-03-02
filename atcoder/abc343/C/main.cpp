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
    
}

int main() {
    ll N;
    cin >> N;
    ll x = cbrt(N);
    for(;x;x--) {
        if (pal(x * x * x)) {
            cout << x * x * x;
            exit(0);
        }
    }
}