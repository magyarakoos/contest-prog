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
    int K = min(sqrt(N * 2), sqrt(M * 2)),
        db = pow(K, 2) / 2;
    N -= db, M -= db;
    cout << (K += (N >= K + 1 && M >= K) || (M >= K + 1 && N >= K));
}
