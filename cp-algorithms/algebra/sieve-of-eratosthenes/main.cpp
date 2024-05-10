#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char* argv[]) {
    ll n = stoll(argv[1]);

    vector is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = 0;

    for (long long i = 2; i * i <= n; i++) {

        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
     
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << '\n';
        }
    }
}
