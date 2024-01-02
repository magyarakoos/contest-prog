#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N;
    cin >> N;
    vector<int> v(N);
    cinv(v);

    int l = 0, r = 0, mx = 1;
    while (r < N - 1) {
        if (v[r] >= v[r + 1]) {
            r++;
            l = r;
        } else {
            r++;
            mx = max(mx, r - l + 1);
        }
    }

    cout << mx;
}
