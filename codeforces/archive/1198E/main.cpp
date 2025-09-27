#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> row_p(1), col_p(1);
    vector<array<int, 4>> rectS(m);
    for (auto& [x1, y1, x2, y2] : rectS) {
        cin >> x1 >> y1 >> x2 >> y2;
        row_p.push_back(y1);
        row_p.push_back(y2);
        col_p.push_back(x1);
        col_p.push_back(x2);
    }

    int k = row_p.size() - 1;
}
