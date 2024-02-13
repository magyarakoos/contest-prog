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

        ll result = 0;

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
                    pairs1.push_back({i})
                }
            }

            mx[modx].push_back(i);
            my[mody].push_back(i);
        }

        cout << result << '\n';
    }
}