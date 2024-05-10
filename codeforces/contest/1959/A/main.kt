#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(100);
    while (N--) {
        int X;
        cin >> X;
        a[X - 1]++;
    }
    for (int i = 0; i < 100; i++) {
        if (a[i] == 1) {
            cout << i + 1 << "\n";
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}