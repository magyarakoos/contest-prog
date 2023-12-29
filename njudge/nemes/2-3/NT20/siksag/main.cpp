#include <iostream>
#include <vector>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)


int N, l, r, bestl, bestr;
int main() {
    cin >> N;
    vector<int> M(N);
    for (int i = 0; i < N; i++) cin >> M[i];

    while (++r < N) {
        cout << l << ' ' << r << '\n';
        if (abs(M[l] - M[r]) > 1) {
            if (bestr - bestl < r - l - 1) {
                bestl = l;
                bestr = r - 1;
            }

            while (1) {
                abs(M[l] - M[r]) > 1
            }

        } else if (bestr - bestl < r - l) {
            bestl = l;
            bestr = r;
        }
    }

    cout << bestl << ' ' << bestr;
}
