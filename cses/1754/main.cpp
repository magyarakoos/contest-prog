#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        int C = 2 * A - B, D = 2 * B - A;
        cout << (C >= 0 && !(C % 3) && D >= 0 && !(D % 3) ? "YES\n" : "NO\n");
    }
}
