#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector H(N, vector<int>(M));
    for (auto& row : H) {
        for (int& x : row) cin >> x;
    }

    while (Q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--, j1--, i2--, j2--;
        cout << format("{} {} {} {}\n", i1, j1, i2, j2);
        cout << h(i1, j1) + h(i2, j2) -
                    2 * lca(i1, j1, i2, j2)
             << "\n";
    }
}
