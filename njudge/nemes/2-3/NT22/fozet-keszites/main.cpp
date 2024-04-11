#include <bits/stdc++.h>
using namespace std;

pair<int, int> simplify(int a, int b) {
	for (int prime : primes) {
		if (a % prime == 0 && b % prime == 0) {
			a /= prime;
			b /= prime;
		}
	}
	return {a, b};
}

void solve() {}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
