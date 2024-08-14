#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    while (N) {
        if (N & 1) {
            result++;
        }
        N >>= 1;
    }
    cout << result;
}
