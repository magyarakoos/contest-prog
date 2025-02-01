#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<array<int, 2>> posS, negS;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0)
            posS.push_back({x, i});
        else if (x < 0)
            negS.push_back({x, i});
        else
            negS.push_back({-1, i});
    }
    sort(posS.begin(), posS.end());
    sort(negS.begin(), negS.end());
    if (negS.size() % 2 == 1) {
        if (posS.empty()) {

            negS[0][0] = -negS[0][0] - 1;
        } else {
            posS.back()[0] = -posS.back()[0] - 1;
            for (int i = posS.size() - 2; i > 0; i -= 2) {
                posS[i][0] = -posS[i][0] - 1;
                posS[i - 1][0] = -posS[i - 1][0] - 1;
            }
        }
    } else {
        for (int i = posS.size() - 1; i > 0; i -= 2) {
            posS[i][0] = -posS[i][0] - 1;
            posS[i - 1][0] = -posS[i - 1][0] - 1;
        }
    }
    vector<int> result(N);
    for (auto [x, i] : posS) result[i] = x;
    for (auto [x, i] : negS) result[i] = x;
    for (int x : result) cout << x << " ";
    cout << "\n";
}
