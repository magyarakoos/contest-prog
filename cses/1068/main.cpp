#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    while (N != 1) {
        cout << N << " ";
        if (N % 2) N /= 2;
        else N *= 3, N += 1;
    }
    cout << "\n";
}