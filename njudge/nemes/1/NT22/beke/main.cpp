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

    int N, M;
    cin >> N >> M;

    map<int, int> from;

    while (M--) {
        int a, b;
        cin >> a >> b;
        from[a] = max(from[a], b);
    }
    from[N] = N;

    point result = {0, 0};
    int pos = 1;

    for (auto [e, v] : from) {
        if (pos >= N) break;
        if (result[0] < e - pos) {
            result[0] = e - pos;
            result[1] = pos;
        }
        if (e == N) break;
        pos = max(pos, v + 1);
    }


    if (result[0] == 0 && result[1] == 0) {
        cout << -1;
    } else {
        if (result[1] + result[0] == N) {
            result[0]++;
        }
        cout << result[0] << ' ' << result[1];
    }
}
