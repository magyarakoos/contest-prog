#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

vector<ll> factorize(ll n) {
    vector<ll> fact;

    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            fact.push_back(d);
            n /= d;
        }
    }

    if (n > 1) fact.push_back(n);

    return fact;
}

int main(int argc, char* argv[]) {
    ll n = stoull(argv[1]);

    for (ll f : factorize(n)) {
        cout << f << '\n';
    }
}