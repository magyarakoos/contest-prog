#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        vector<int> v(N);
        cinv(v);

        unordered_map<int, vector<int>> mx, my;

        vector<array<int, 2>> pairs1, pairs2;

        for (int i = 0; i < N; i++) {
            int modx = v[i] % X,
                mody = v[i] % Y;

            // a - b = 0
            // b = mody
            // a - mody = 0
            // a = mody

            if (mx.count(X - modx) && my.count(mody)) {
                for (int ind : mx[X - modx]) {
                    pairs1.push_back({ind, i});
                }
                for (int ind : my[mody]) {
                    pairs1.push_back({ind, i});
                }
            }

            mx[modx].push_back(i);
            my[mody].push_back(i);
        }

        for (auto p : pairs1) {
            cerr << p[0] << ' ' << p[1] << '\n';
        }
        cerr << '\n';
        for (auto p : pairs2) {
            cerr << p[0] << ' ' << p[1] << '\n';
        }
        cerr << "\n\n";

        sort(all(pairs1));
        sort(all(pairs2));

        auto it1 = pairs1.begin();
        auto it2 = pairs2.begin();

        ll result = 0;

        while (it1 != pairs1.end() && it2 != pairs2.end()) {
            if (*it1 == *it2) {
                result++;
                it1++;
                it2++;
            } else if (*it1 < *it2) {
                it1++;
            } else {
                it2++;
            }
        }
    }
}