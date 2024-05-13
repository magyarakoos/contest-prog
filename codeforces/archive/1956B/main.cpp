#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    multiset<int> a, b, c;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        a.insert(X);
    }
    for (int i = 0; i < N; i++) {
        int cnt = 2 - a.count(i + 1);
        for (int j = 0; j < cnt; j++) {
            b.insert(i + 1);
        }
    }
    while (!a.empty()) {
        for (int x : c) {
            a.contains(x);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}