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

    bool A_free = 0, E_free = 0;
    for (const auto& v : m) {
        for (auto [c,])
    }
}