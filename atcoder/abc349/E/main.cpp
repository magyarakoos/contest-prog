#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m[9], d[9], sum, INF = 1e10;
set<int> s;

bool over(int c) {
    for(int i=0; i<3; i++){
        if(c[3*i]==c[3*i+1] && c[3*i+1]==c[3*i+2]) return true;
        if(c[i]==c[i+3] && c[i+3]==c[i+6]) return true;
    }
    if(c[0]==c[4] && c[4]==c[8]) return true;
    if(c[2]==c[4] && c[4]==c[6]) return true;
    return false;
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
                    if (abs(e) != INF) e += m[i];
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
    cout << backtrack(1) << "\n";
    // cout << (backtrack(1) + INF > (sum + INF * 2) / 2 ? "Takahashi" : "Aoki");
}
