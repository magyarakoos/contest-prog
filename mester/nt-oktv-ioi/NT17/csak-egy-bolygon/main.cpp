#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using intv = struct { int e; int v; };

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    vector<intv> AX(A);
    for (auto [k, v] : AX) cin >> k >> v;

    vector<intv> BX(A);
    for (auto [k, v] : BX) cin >> k >> v;

    vector<intv> result;
    int ap = 0, bp = 0;

    cout << size(result) << '\n';

    
}