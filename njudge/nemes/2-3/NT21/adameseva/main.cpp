// O(A log(A) + E log(A + E))
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    map<int, vector<pair<char, bool>>> m;
    int P, A, E;
    cin >> P >> A;

    while (A--) {
        int AK, AV;
        cin >> AK >> AV;
        m[AK].push_back({'A', 1});
        m[AV].push_back({'A', 0});
    }

    cin >> E;
    while (E--) {
        int EK, EV;
        cin >> EK >> EV;
        m[EK].push_back({'E', 1});
        m[EV].push_back({'E', 0});
    }

    vector<array<int, 2>> result;

    bool A_free = 0, E_free = 0;
    for (const auto& [t, v] : m) {
        for (auto [c, b] : v) {
            if (c == 'A') {
                A_free = b;
            } else {
                E_free = b;
            }
        }

        if (A_free && E_free) {

        } else {
            if (result.back()[1] == -1) {
                result.back()[1] = t;
            }
        }
    }
}