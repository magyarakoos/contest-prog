#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int solve(const vector<int>& v) {
    vector<int> prev(v.size(), -1);
}

int main() {
    speed;

    int N;
    cin >> N;

    vector<int> u(N), v;
    cinv(u);
    v = u;
    reverse(all(v));

    int result = max(solve(u), solve(v));
    cout << (result < 2 ? -1 : result);
}
