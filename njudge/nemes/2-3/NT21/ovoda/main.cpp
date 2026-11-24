#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> m(k);
    vector<array<int, 3>> kid(n);
    for (int& x : m) cin >> x;
    for (int i = 0; i < n; i++) {
        cin >> kid[i][1];
        kid[i][1]--;
        kid[i][2] = i;
    }
    for (int i = 0; i < n; i++) cin >> kid[i][0];
    sort(kid.rbegin(), kid.rend());

    int result = 0;
    vector<int> todo;
    for (int i = 0; i < n; i++) {
        auto [cry_time, chosen, index] = kid[i];
        if (m[chosen]) {
            m[chosen]--;
        } else {
            todo.push_back(i);
            result += cry_time;
        }
    }
    cout << result << "\n";
}
