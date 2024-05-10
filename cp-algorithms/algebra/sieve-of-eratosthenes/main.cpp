#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    size_t n = stoul(argv[1]);
    
    vector is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = 0;

    for (size_t i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (size_t j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (size_t i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << "\n";
        }
    }
}
