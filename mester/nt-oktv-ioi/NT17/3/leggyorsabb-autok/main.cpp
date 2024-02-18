#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<int> make_intersect(const set<array<int, 2>>& s, const set<array<int, 2>>& t) {

    vector<int> result;

    auto sit = s.begin();
    auto tit = t.begin();

    while (sit != s.end() && tit != t.end()) {

        if ((*sit)[0] == (*tit)[0]) {
            result.push_back((*tit)[1] - (*sit)[1]);
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

    for (int i = 0; i < N; i++) {
        cerr << i + 1 << " : ";
        for (auto [carid, min] : v[i]) {
            cerr << '(' << carid << ',' << min << ") ";
        }
        cerr << '\n';
    }

    vector<vector<int>> intersectS(N - 1);

    for (int i = 0; i < N - 1; i++) {
        
    }
}