#include <bits/stdc++.h>
using namespace std;
using u8 = unsigned char;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define size(v) (int)v.size()

double solve(vector<u8> v) {
    if (!sum(v)) {
        return 0;
    }
    for (int i = 0; i < size(v); i++) {
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<u8> v(N);
    for (u8& x : v) cin >> x;
    cout << solve(v);
}
