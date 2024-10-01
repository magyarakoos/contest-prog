#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> H(N);
    for (int& x : H) cin >> x;

    while (Q--) {
        int S, K;
        cin >> S >> K;

        int result = H[S - 1];
        for (int i = 0; i < K; i++) {
            result = max(result, H[S + pow(2, i) - 1] - 1);
        }

        cout << result << "\n";
    }
}
