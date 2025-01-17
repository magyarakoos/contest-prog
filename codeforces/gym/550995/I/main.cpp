#include <iostream>
#include <vector>
using namespace std;

inline constexpr int MAXN = 7368790, MAXK = 5e5;

vector<int> create(int n) {
    vector<int> a(n, 1);
    a[0] = a[1] = 0;
    for (int i = 2; i < n; i++) {
        if (a[i]) {
            for (int j = 2 * i; j < n; j += i) a[j] = 0;
        }
    }
    return a;
}

void io(const vector<int>& primes) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        cout << primes[K - 1] << "\n";
    }
}

int main() {
    const int stage_a = 1e4;
    vector<int> a = create(stage_a);
}
