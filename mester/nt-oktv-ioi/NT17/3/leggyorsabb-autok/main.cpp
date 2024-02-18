#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<set<array<int, 2>>> v(N);

    while (M--) {
        int carid, placeid, hour, min;
        cin >> carid >> placeid >> hour >> min;
        min += hour * 60;
        placeid--;

        v[placeid].insert({carid, min});
    }

    for (int i = 0; i < N; i++) {
        cerr << i + 1 << " : ";
        for (auto [carid, min] : v[i]) {
            cerr << '(' << carid << ',' << min << ") ";
        }
        cerr << '\n';
    }
}