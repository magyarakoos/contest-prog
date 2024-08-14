#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<array<int, 2>> make_intersect(const set<array<int, 2>>& s, const set<array<int, 2>>& t) {

    vector<array<int, 2>> result;

    auto sit = s.begin();
    auto tit = t.begin();

    while (sit != s.end() && tit != t.end()) {

        if ((*sit)[0] == (*tit)[0]) {
            result.push_back({(*sit)[0], (*tit)[1] - (*sit)[1]});
            sit++;
            tit++;
        } else if ((*sit)[0] < (*tit)[0]) {
            sit++;
        } else {
            tit++;
        }
    }

    return result;
}

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

    #ifdef LOCAL
    for (int i = 0; i < N; i++) {
        cerr << i + 1 << " : ";
        for (auto [carid, min] : v[i]) {
            cerr << '(' << carid << ',' << min << ") ";
        }
        cerr << '\n';
    }
    #endif

    vector<vector<array<int, 2>>> intersectS(N - 1);

    for (int i = 0; i < N - 1; i++) {
        intersectS[i] = make_intersect(v[i], v[i + 1]);
    }

    #ifdef LOCAL
    for (int i = 0; i < N - 1; i++) {
        cerr << i + 1 << " : ";
        for (auto [carid, x] : intersectS[i]) {
            cerr << '(' << carid << ',' << x << ") ";
        }
        cerr << '\n';
    }
    #endif
    
    for (int i = 0; i < N - 1; i++) {
        int best = INT_MAX, bestid = 0;
        for (auto [carid, x] : intersectS[i]) {
            if (x >= 0) {
                if (x < best) {
                    best = x;
                    bestid = carid;
                }
            }
        }
        cout << bestid << ' ';
    }
    cout << '\n';

    for (int i = 0; i < N - 1; i++) {
        int best = INT_MAX, bestid = 0;
        for (auto [carid, x] : intersectS[i]) {
            x *= -1;
            if (x >= 0) {
                if (x < best) {
                    best = x;
                    bestid = carid;
                }
            }
        }
        cout << bestid << ' ';
    }
    cout << '\n';
}
