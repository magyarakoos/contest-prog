#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> P(N), pos(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        pos[--P[i]] = i;
    }
}
