#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> m(k);
    vector<array<int, 2>> kid(n);
    for (int& x : m) cin >> x;
    for (int i = 0; i < n; i++) {
        cin >> kid[i][1] >> kid[i][0];
        kid[i][1]--;
    }
    sort(kid.rbegin(), kid.rend());
    vector<int> cnt(k);
    int result = 0;
    vector<int> todo;
    for (int i = 0; i < n; i++) {
        int s = kid[i][1], t = kid[i][0];
        if (cnt[s] == m[s]) {
            todo.push_back(i);
            result += t;
        } else {
            cnt[s]++;
        }
    }
    cout << result << "\n";
}
