#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll prod(const vector<ll>& a, int mask, int N) {
    int n = a.size();
    ll result = 1;
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
            result *= a[i];
            if (result >= N) {
                return N + 1;
            }
        }
    }
    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    ll result = 0;

    vector<ll> a(K);
    for (ll& x : a) cin >> x, result += N / x;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < i; j++) {
            result -=
        }
    }


    cout << result << "\n";
}
