#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int A, B;
    cin >> A >> B;
#define sgn(x) (x > 0) - (x < 0)
    cout << (sgn(A) == sgn(B) ? "Yes" : "No") << "\n";
}
