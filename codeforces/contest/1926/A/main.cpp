#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int ac = 0, bc = 0;
        for (int i = 0; i < 5; i++) {
            char c;
            cin >> c;
            if (c == 'A') ac++;
            if (c == 'B') bc++;
        }

        cout << (ac > bc ? "A\n" : "B\n");
    }
}
