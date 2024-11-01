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
    vector<int> a(N), ss(N);
    for (int& x : a) cin >> x;

    partial_sum(a.rbegin(), a.rend(), ss.rbegin());

    unordered_set<int> s;
    s.insert(a[0]);

    vector<unordered_map<int, int>> pathS(N);
    pathS[0][a[0]] = 0;

    for (int i = 1; i < N; i++) {
        unordered_set<int> ns;
        for (int x : s) {
            ns.insert(x + a[i]);
            pathS[i][x + a[i]] = x;

            if (x - a[i] >= 0) {
                ns.insert(x - a[i]);
                pathS[i][x - a[i]] = x;
            }
        }
        swap(s, ns);
    }

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
                result[i] = x - pathS[i][x];
                x = pathS[i][x];
            }

            for (int x : result) {
                cout << string(abs(x), "()"[x < 0]);
            }
            cout << "\n";

            exit(0);
        }
    }

    cout << "-1\n";
}
