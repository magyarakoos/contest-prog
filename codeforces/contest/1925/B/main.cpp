#include <bits/stdc++.h>
using namespace std;

void solve() {
    int X, N;
    cin >> X >> N;

    int base = X / N;

    if (X % N == 0) {
        cout << base << '\n';
        return;
    }
    
    int result = 0;

    while (base) {
        result = max(result, gcd(base, base + (X % base)));

        if (base == base + (X % base)) {
            break;
        }
        
        base--;
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
