#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

int t[4 * MAXN + 1];

void update(int curr, int tl, int tr, int l, int r, int val) {

}

int query(int curr, int tl, int tr, int pos) {
    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    while (N--) {
        int P, D;
        cin >> P >> D;
        update(1, 0, H - 1, P, P + K, D);
    }
    int mn = INT_MAX;
    for (int i = 0; i < H; i++) {
        mn = min(mn, query(1, 0, H - 1, i));
    }
    cout << mn;
}