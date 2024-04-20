#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 1;

ll t[MAXN];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl]
    }
}


int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {

        } else {

        }
    }
}