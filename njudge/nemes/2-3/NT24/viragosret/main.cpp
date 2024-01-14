#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)
using namespace std;

int N, K, M;
int main() {
    speed;

    cin >> N >> K;
    while (N--) {
        char c; cin >> c;
        M += c == '1';
    }

    long long result = 0;
    for (int i = 0; i < M; i++) {
        int curr = M - (i + K) + 1;
        if (curr > 0) result += curr;
    }

    cout << result;
}
