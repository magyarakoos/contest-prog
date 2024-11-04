#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> M(N), R(N);
    for (int i = 0; i < N; i++) { cin >> M[i] >> R[i]; }
    int Q;
    cin >> Q;
    while (Q--) {
        int T, D;
        cin >> T >> D;
        int m = M[T - 1], r = R[T - 1];
        // D / Q
    }
}
