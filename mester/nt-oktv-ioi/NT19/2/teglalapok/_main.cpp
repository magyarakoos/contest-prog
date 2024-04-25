#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    while (N--) {
        int P, D;
        cin >> P >> D;
        update(1, 0, H, P + 1, P + K, D);
    }
    int mn = INT_MAX;
    for (int i = 1; i <= H; i++) {
        mn = min(mn, query(1, 0, H, i));
    }
    cout << mn << "\n";
}
