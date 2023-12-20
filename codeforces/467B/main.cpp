#include <bits/stdc++.h>
using namespace std;

int common_bits(int a, int b) {
    a ^= b;
    int result = 0;
    while (a) {
        if (a & 1) result++;
        a >>= 1;
    }
    return result;
}

int N, M, K, fedor, result;
int main() {
    cin >> N >> M >> K;
    vector<int> X(M);
    for (int& Xi : X) {
        cin >> Xi;
    }
    cin >> fedor;

    for (int Xi : X) {
        result += common_bits(Xi, fedor) <= K;
    }

    cout << result;
}
