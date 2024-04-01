#include <bits/stdc++.h>
using namespace std;

long long N, X, A, sum, divS;
int main() {
    cin >> N >> X;
    while (N--) {
        cin >> A;
        sum += A;
        divS += A / X;
    }
    cout << min(sum / (X + 1), divS);
}
