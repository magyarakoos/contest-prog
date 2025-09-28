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
        x2++, y2++;
        row.push_back(y1);
        row.push_back(y2 + 1);
        col.push_back(x1);
        col.push_back(x2 + 1);
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    row.erase(unique(row.begin(), row.end()), row.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    map<int, int> row_pos, col_pos;
    for (int i = 0; i < row.size(); i++) {
        row_pos[row[i]] = i;
    }
    for (int i = 0; i < col.size(); i++) {
        col_pos[col[i]] = i;
    }

    for (int x : row) cout << x << " ";
    cout << "\n";
    for (int x : col) cout << x << " ";
    cout << "\n";

    int k = row.size() - 1, l = col.size() - 1;
    vector grid(k, vector<bool>(l));

    for (auto [x1, y1, x2, y2] : rectS) {
        for (int i = col_pos[y1]; i <= col_pos[y2]; i++) {
            for (int j = row_pos[x1]; j <= row_pos[x2];
                 j++) {
                grid[i][j] = 1;
            }
        }
    }
}
