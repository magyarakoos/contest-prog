#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m[9], d[9], sum, INF = 1e10;
set<int> s;

ll backtrack(int x) {
    if (s.size() == 9) return 0;

    ll ans = x == 1 ? -INF : INF;

    for (int i = 0; i < 9; i++) {
        if (!s.count(i)) {
            s.insert(i);
            d[i] = x;

            

            d[i] = i;
            s.erase(i);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < 9; i++) {
        d[i] = i;
        cin >> m[i];
        sum += m[i];
    }


}