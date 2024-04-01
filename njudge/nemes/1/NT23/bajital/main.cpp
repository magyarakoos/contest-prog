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

    int N, X;
    cin >> N >> X;

    set<array<int, 2>> divS;
    set<array<int, 2>, greater<array<int, 2>>> remS;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        int div = A / X, rem = A - div * X;
        if (div) divS.insert({div, i});
        if (rem) remS.insert({rem, i});
    }

    while (1) {
        
    }
}
