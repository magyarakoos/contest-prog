#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    bool a_found = 0, b_found = 0, c_found = 0;
    int acnt = 0, bcnt = 0, ccnt = 0;
    for (char c : s) {
        acnt += c == 'A';
        bcnt += c == 'B';
        ccnt += c == 'C';
    }
    for (int i = 0; i < n; i++) {
        char c = s[i];
        a_found |= c == 'A';
        b_found |= c == 'B';
        c_found |= c == 'C';
        if (a_found && b_found && c_found) {}
    }
}
