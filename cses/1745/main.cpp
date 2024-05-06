#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
    int N;
    cin >> N;
    vector<int> v(N), ps(N + 1);
    for (int& x : v) cin >> x;
    partial_sum(all(v), ps.begin() + 1);

    set<int> s;
    for (int r = 1; r <= N; r++) {
        for (int l = 0; l < r; l++) {
            s.insert(ps[r] - ps[l]);
        }
    }

    cout << sz(s) << "\n";
    for (int x : s) cout << x << " ";
    cout << "\n";
}
