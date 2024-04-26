#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

void solve() {
    array<int, 2> a {INT_MAX, INT_MAX};
    int N, res = 0;
    cin >> N;
    while (N--) {
        int X;
        cin >> X;

        if (a[0] == X || a[1] == X) {
            continue;
        }

        if (a[0] < X && a[1] < X) {
            a[min_element(all(a)) - a.begin()] = X;
            res++;
            continue;
        }

        if (a[0] > X && a[1] > X) {
            a[min_element(all(a)) - a.begin()] = X;
            continue;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}