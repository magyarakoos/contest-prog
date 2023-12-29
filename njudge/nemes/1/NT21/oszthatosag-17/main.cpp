#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    int N, pc = 0;
    cin >> N;
    cout << (N % 17 ? "NEM" : "IGEN") << '\n';

    while (0 < N) {
        N = (N / 10) - (N % 10) * 5;
        if (0 <= N) {
            cout << N << ' ';
            pc++;
        }
    }

    if (!pc) cout << '\n';
}
