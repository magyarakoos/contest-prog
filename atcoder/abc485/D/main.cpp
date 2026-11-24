#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    int acnt = 0, bcnt = 0, ccnt = 0;
    vector<int> aps(n), bps(n), cps(n);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        aps[i] = c == 'A';
        bps[i] = c == 'B';
        cps[i] = c == 'C';
        if (i) {
            aps[i] += aps[i - 1];
            bps[i] += bps[i - 1];
            cps[i] += cps[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        char c = s[i];
        acnt += c == 'A';
        bcnt += c == 'B';
        ccnt += c == 'C';
        if (acnt && bcnt && ccnt) {}
    }
}
