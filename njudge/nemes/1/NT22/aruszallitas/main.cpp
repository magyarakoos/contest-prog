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
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        from[a] = max(from[a], b);
    }
    from[N] = N;

    int result = 0, pos = 1;

    for (auto [a, b] : from) {
        if (pos >= N) break;
        if (pos < a) result += a - pos;
        pos = max(pos, b);
    }

    cout << result;
}
