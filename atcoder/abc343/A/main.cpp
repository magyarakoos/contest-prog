#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

ifstream f("../input");

#ifdef LOCAL
#define cin f
#endif

int main() {
    int A, B, i = 10;
    cin >> A >> B;
    while (i--) {
        if (i != A + B) {
            cout << i;
            exit(0);
        }
    }
}
