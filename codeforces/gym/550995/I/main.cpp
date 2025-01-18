#include <bits/stdc++.h>
using namespace std;

inline constexpr int MAXP = 7'368'788, MAXK = 500'000;

bitset<MAXP> sieve;
int primes[MAXK];

void generate_primes() {
    primes[0] = 2;
    int ind = 1;
    for (int64_t i = 3; i < MAXP; i += 2) {
        if (!sieve[i]) {
            primes[ind++] = i;
            for (int64_t j = i * i; j < MAXP; j += 2 * i)
                sieve[j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    generate_primes();

    int q;
    cin >> q;

    while (q--) {
        int a;
        cin >> a;
        cout << primes[a - 1] << '\n';
    }
}
