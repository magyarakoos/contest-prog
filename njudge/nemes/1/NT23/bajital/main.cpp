#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, x, remS = 0, divS = 0;
    cin >> N >> x;

    while (N--) {
        int a;
        cin >> a;
        remS += a % x;
        divS += a / x;
    }

    while (divS > remS) {
        divS--;
        remS += x;
    }

    cout << divS;
}
