#include <bits/stdc++.h>
using namespace std;
using u8 = unsigned char;
#define sum(v) accumulate(v.begin(), v.end(), 0)

double solve(vector<u8> v) {
    if (!sum(v)) {
        return 0;
    }
    // a = (v[1] - 1)
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<u8> v(N);
    for (u8& x : v) cin >> x;
    cout << solve(v);
}
