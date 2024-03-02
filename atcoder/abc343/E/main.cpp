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
    int A, B, C;
    cin >> A >> B >> C;

    int volume = A + B * 2 + C * 3;

    if (volume != 3 * 7 * 7 * 7)
}