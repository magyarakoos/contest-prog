#include <bits/stdc++.h>
using namespace std;

void solve() {
    int K, Q;
    cin >> K >> Q;
    bitset<100> bs;
    while (K--) {
        int A;
        cin >> A;
        bitset<100> bs2(1);
        bs2 <<= 100 - A;
        bs |= bs2;
    }
    while (Q--) {
        int N;
        cin >> N;
        bitset<100> bs2;
        bs2.set();
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}