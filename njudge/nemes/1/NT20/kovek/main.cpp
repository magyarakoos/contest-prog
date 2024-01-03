#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    int N, avg = 0, result = 0;
    cin >> N;

    vector<int> prefix(N);

    for (int i = 0; i < N; i++) {
        cin >> prefix[i];
        avg += prefix[i];

        if (i) prefix[i] += prefix[i - 1];
    }

    avg /= N;

    for (int i = 0; i < N - 1; ) {
        result += prefix[i] != avg * ++i;
    }

    cout << result;
}
