// thanks to the creative genius of TomaSajt
#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int N;
int solve(const vector<int>& v) {
    vector<int> prev(N, -1);
    int result = 0;
    for (int i = 0; i < N; i++) {
        prev[i] = i - 1;
        while (prev[i] != -1 && v[prev[i]] < v[i]) {
            prev[i] = prev[prev[i]];
        }
        if (prev[i] != -1) {
            result = max(result, i - prev[i]);
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;

    vector<int> u(N), v;
    cinv(u);
    v = u;
    reverse(all(v));

    int result = max(solve(u), solve(v));
    cout << (result < 2 ? -1 : result);
}
