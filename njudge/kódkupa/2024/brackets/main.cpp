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
    vector<int> a(N), ss(N);
    for (int& x : a) cin >> x;

    partial_sum(ss.rbegin(), ss.rend(), a.rbegin());

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

            to_add[j++] = x - a[i];
            pathS[i][x - a[i]] = x;
        }
        s.insert(to_add.begin(), to_add.begin() + j);
    }

    for (int x : s) {
        if (!x) {
            vector<int> result(N);
            for (int i = N - 1; i >= 0; i--) {
                result[i] = x;
                x = pathS[i][x];
            }
            for (int x : result) cout << x << " ";
            cout << "\n";
            exit(0);
        }
    }

    cout << "IMPOSSIBLE\n";
}
