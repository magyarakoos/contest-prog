#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    int abs_mn = *min_element(a.begin(), a.end(),
                              [](int x, int y) { return abs(x) < abs(y); });
}
