#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    vector<int> v(H + 1);
    while (N--) {
        int P, D;
        cin >> P >> D;
        v[P - 1] += D;
        v[P + K] -= D;
    }
    int res = 0;
    for (int i = 1; i < H; i++) {
        v[i] += v[i - 1];
        res = );
    }

}
