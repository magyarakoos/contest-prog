#include <bits/stdc++.h>
using namespace std;

// itt gondolom valami DP lett volna a várt megoldás,
// de belefért egy brute force is

int main() {
    int N, W, w0, v0, w, v;
    cin >> N >> W >> w0 >> v0;

    vector<vector<int>> a(4);
    a[0].push_back(v0);

    while (--N) {
        cin >> w >> v;
        a[w - w0].push_back(v);
    }

    for (int i = 0; i <= 3; i++) {
        sort(a[i].rbegin(), a[i].rend());
        a[i].insert(a[i].begin(), 0);
        partial_sum(a[i].begin(), a[i].end(), a[i].begin());
    }

    int result = 0;

    for (int i = 0; i < a[0].size(); i++) {
        for (int j = 0; j < a[1].size(); j++) {
            for (int k = 0; k < a[2].size(); k++) {
                for (int l = 0; l < a[3].size(); l++) {
                    if ((i + j + k + l) * (long long)w0 +
                            j + 2 * k + 3 * l >
                        W) {
                        continue;
                    }
                    result =
                        max(result, a[0][i] + a[1][j] +
                                        a[2][k] + a[3][l]);
                }
            }
        }
    }

    cout << result << "\n";
}
