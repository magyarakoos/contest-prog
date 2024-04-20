#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m[9], d[9], sum, INF = 1e11;
set<int> s;

bool over() {
    return 
        (d[0] == d[1] && d[1] == d[2]) ||
        (d[3] == d[4] && d[4] == d[5]) ||
        (d[6] == d[7] && d[7] == d[8]) ||
        (d[0] == d[3] && d[3] == d[6]) ||
        (d[1] == d[4] && d[4] == d[7]) ||
        (d[2] == d[5] && d[5] == d[8]) ||
        (d[0] == d[4] && d[4] == d[8]) ||
        (d[2] == d[4] && d[4] == d[6]) 
    ;
}

ll backtrack(int x) {
    if (s.size() == 9) return 0;

    ll ans = x == 1 ? -INF : INF;

    for (int i = 0; i < 9; i++) {
        if (!s.count(i)) {
            s.insert(i);
            d[i] = x;

            if (!over()) {
                if (x == 1) {
                    ll e = backtrack(2);
                    if (abs(e) != INF) {
                        e += m[i];
                    }
                    ans = max(ans, e);
                } else {
                    ans = min(ans, backtrack(1));
                }
            }            

            d[i] = i;
            s.erase(i);
        }
    }

    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < 9; i++) {
        d[i] = i;
        cin >> m[i];
        sum += m[i];
    }
    cout << (backtrack(1) + INF * 10 > (sum + INF * 20) / 2 ? "Takahashi" : "Aoki");
}
