#include <bits/stdc++.h>
using namespace std;
#define int int64_t

using point = array<int, 2>;
using node = array<point, 2>;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    auto read = []() {
        int N;
        cin >> N;
        vector<pair<point, int>> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i].first[0] >> a[i].first[1];
            a[i].second = i;
        }
        return a;
    };
    auto A = read(), B = read();
}
