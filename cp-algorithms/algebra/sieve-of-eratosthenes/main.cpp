#include <bits/stdc++.h>
using namespace std;

void sieve_of_eratosthenes(int n) {
    
}
 
int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);

    bool is_prime[n + 1];
    memset(is_prime, 1, n + 1);

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
