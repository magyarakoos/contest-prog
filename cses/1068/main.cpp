#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    while (1) {
        cout << N << " ";
        if (N != 1) {
            if (N % 2) N *= 3, N++;
            else N /= 2;
        } else break;
    }
    cout << "\n";
}