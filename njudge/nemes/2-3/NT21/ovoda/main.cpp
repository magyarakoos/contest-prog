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
    vector<int> todo, ass(n);
    for (int i = 0; i < n; i++) {
        auto [cry_time, chosen, index] = kid[i];
        if (m[chosen]) {
            m[chosen]--;
            ass[index] = chosen + 1;
        } else {
            todo.push_back(index);
            result += cry_time;
        }
    }
    for (int i = 0; i < k; i++) {
        while (m[i] && !todo.empty()) {
            m[i]--;
            ass[todo.back()] = i + 1;
            todo.pop_back();
        }
        if (todo.empty()) break;
    }
    cout << result << "\n";
    for (int x : ass) cout << x << " ";
    cout << "\n";
}
