#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), result(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        result[0] += (i & 1 ? -1 : 1) * a[i];
    }
    result[N - 1] = (a[N - 1] - result[0] / 2) * 2;

    for (int i = N - 2; i > 0; i--) {
        result[i] = (a[i] - result[i + 1] / 2) * 2;
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}
