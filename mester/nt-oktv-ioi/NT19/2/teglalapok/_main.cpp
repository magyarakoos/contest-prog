#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    vector<int> v(H + 2);
    while (N--) {
        int P, D;
        cin >> P >> D;
        v[P] += D;
        v[P + K + 1] -= D;
    }
    int res = 0;
    for (int i = 1; i <= H; i++) {
        res = min(res, (v[i] += v[i - 1]));
    }
    cout << res;
}
