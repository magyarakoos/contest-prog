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

    v[1] += v[0];

    for (int i = 2; i < N; i++) {
        v[i] = min(v[i - 1], v[i - 2]) + v[i];
    }

    cout << v[N - 1];
}
