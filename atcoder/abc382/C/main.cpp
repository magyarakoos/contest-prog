#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i) { A[i] = min(A[i - 1], A[i]); }
    }
    A.push_back(0);

    for (int i = 0; i < M; i++) {
        int l = -1, r = N, B;
        cin >> B;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] <= B) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << (r == N ? -1 : r + 1) << "\n";
    }
}
