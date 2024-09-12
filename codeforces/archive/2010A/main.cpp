#include <iostream>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N, x, i = 0, res = 0;
        cin >> N;
        while (N--) {
            cin >> x;
            res += x * (i++ & 1 ? 1 : -1);
        }
        cout << res << "\n";
    }
}
