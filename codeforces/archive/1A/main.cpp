#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double N, M, A;
    cin >> N >> M >> A;
    cout << (ll)ceil(N / A) * (ll)ceil(M / A);
}
