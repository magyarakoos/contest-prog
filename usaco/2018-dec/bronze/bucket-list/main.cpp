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
    vector<point> v(2 * N);
    for (int i = 0, p = 0; i < N; i++) {
        int S, T, B;
        cin >> S >> T >> B;
        v[p] = {S, B}; p++;
        v[p] = {T, -B}; p++;
    }

    sort(all(v));

    int curr = 0, mx = 0;
    for (int i = 0; i < 2 * N; i++) {
        curr += v[i][1];
        mx = max(mx, curr);
    }

    cout << mx;
}
