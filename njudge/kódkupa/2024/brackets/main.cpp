#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    // for (int x : a) cout << x << " ";
    // cout << "\n\n";

    unordered_set<int> s;
    s.insert(a[0]);

    vector<unordered_map<int, int>> pathS(N);
    pathS[0][a[0]] = 0;

    vector<int> to_add(500 * 5e4 + 5);

    for (int i = 1; i < N; i++) {
        int j = 0;
        for (int x : s) {
            to_add[j++] = x + a[i];
            pathS[i][x + a[i]] = x;

            if (x - a[i] >= 0) {
                to_add[j++] = x - a[i];
                pathS[i][x - a[i]] = x;
            }
            // cout << x + a[i] << " " << x - a[i] << "\n";
        }
        s.insert(to_add.begin(), to_add.begin() + j);
    }
    // cout << "\n";

    // for (int i = 0; i < N; i++) {
    //     cout << i << ":\n";
    //     for (auto [k, v] : pathS[i]) {
    //         cout << k << " " << v << "\n";
    //     }
    //     cout << "\n";
    // }

    for (int x : s) {
        if (!x) {
            vector<int> result(N);
            for (int i = N - 1; i >= 0; i--) {
                x = result[i] = pathS[i][x];
            }
            result.push_back(0);

            for (int i = 1; i <= N; i++) {
                int d = result[i] - result[i - 1];
                assert(d != 0);
                cout << string(abs(d), "()"[d < 0]);
            }
            cout << "\n";

            exit(0);
        }
    }

    cout << "-1\n";
}
