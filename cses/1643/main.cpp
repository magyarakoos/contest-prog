#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (ll& x : a) cin >> x;

    ll result = INT_MIN, curr = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, curr = max(curr + a[i], a[i]));
    }

    cout << result;
}
