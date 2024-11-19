#include <bits/stdc++.h>
using namespace std;

// meg van adva a példában, hogy a maximális értékhez mennyi
// művelet kell állítom, hogy ennél több művelet nem kell
// semmihez
const int MX = 63244;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i <= MX; i++) {
            if (((i + 1) / 2 + 1) * (i / 2 + 1) >= N) {
                cout << i << "\n";
                break;
            }
        }
    }
}
