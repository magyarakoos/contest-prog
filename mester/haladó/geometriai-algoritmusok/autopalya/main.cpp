#include <bits/stdc++.h>
using namespace std;
#define int int64_t

using point = array<int, 2>;
using node = array<point, 2>;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<node> P(2e5);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i][0][0] >> P[i][0][1];
        P[i][1] = {0, i};
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> P[i + N][0][0] >> P[i + N][0][1];
        P[i + N][1] = {1, i - N};
    }
    P.resize(N + M);

    sort(P.begin(), P.end());
    sort(P.begin() + 1, P.end(),
         [&](auto A, auto B) { return 0; });
}
