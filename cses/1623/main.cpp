#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    ll result = LLONG_MAX, sum = accumulate(a.begin(), a.end(), 0LL);

    for (int mask = 0; mask < (1 << N); mask++) {
        ll curr = 0;
        for (int i = 0; i < N; i++) {
            curr += a[i] * (mask >> i & 1);
        }
        result = min(result, abs(sum - curr * 2));
    }

    cout << result << "\n";
}
