#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> row(1, 1), col(1, 1);
    vector<array<int, 4>> rectS(m);
    for (auto& [x1, y1, x2, y2] : rectS) {
        cin >> x1 >> y1 >> x2 >> y2;
        row.push_back(y1);
        row.push_back(y2);
        col.push_back(x1);
        col.push_back(x2);
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    row.erase(unique(row.begin(), row.end()), row.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    for (int x : row) cout << x << " ";
    cout << "\n";
    for (int x : col) cout << x << " ";
    cout << "\n";
}
