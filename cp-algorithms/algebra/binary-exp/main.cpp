#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll exp_recur(ll a, ll n) {

    if (!n) return 1;

    ll res = exp_recur(a, n / 2);

    return res * res * (n % 2 ? a : 1); 
}

ll exp_fast(ll a, ll n) {

    ll result = 1;

    while (0 < n) {
        if (n & 1) result *= a; // the right most bit of n is 1 (it's odd)
        a *= a; // a^a
        n >>= 1; // div by 2
    }

    return result;
}

int main(int argc, char* argv[]) {
    int 
        A = stoi(argv[1]), 
        N = stoi(argv[2]);

    cout << exp_fast(A, N) << endl;
}
