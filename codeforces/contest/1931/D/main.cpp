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
                    pairs1.push_back({ind, i});
                }
                for (int ind : my[mody]) {
                    pairs1.push_back({ind, i});
                }
            }

            mx[modx].push_back(i);
            my[mody].push_back(i);
        }

                // Sort the vectors to enable efficient intersection check
        sort(all(pairs1));
        sort(pairs2.begin(), pairs2.end());

        // Create iterators for pairs1 and pairs2
        auto it1 = pairs1.begin();
        auto it2 = pairs2.begin();

        // Initialize a counter for intersecting elements
        int intersectCount = 0;

        // Iterate through both vectors
        while (it1 != pairs1.end() && it2 != pairs2.end()) {
            if (*it1 == *it2) {
                // Increment the counter if elements are equal (intersection found)
                intersectCount++;
                it1++;
                it2++;
            } else if (*it1 < *it2) {
                // Move to the next element in pairs1
                it1++;
            } else {
                // Move to the next element in pairs2
                it2++;
            }
        }

    }
}