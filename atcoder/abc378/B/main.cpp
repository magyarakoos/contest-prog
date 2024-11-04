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
        int fi = D / M[T - 1] * M[T - 1] + R[T - 1];
        cout << fi + M[T - 1] * (fi < D) << "\n";
    }
}
