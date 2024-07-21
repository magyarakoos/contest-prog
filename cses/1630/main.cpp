#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<array<int, 2>> v(N);
    for (auto& [a, d] : v) cin >> a >> d;

    sort(v.begin(), v.end());

    ll t = 0, result = 0;

    for (auto [a, d] : v) {
        t += a;
        result += d - t;
    }

    cout << result;
}
