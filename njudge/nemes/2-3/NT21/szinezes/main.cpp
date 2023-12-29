#include <iostream>
#include <vector>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int main() {
    speed;

    int N, Q;
    cin >> N >> Q;
    vector<bool> balls(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        balls[i] = c == '1';
    }

    int z_sum = 0, o_sum = 0, i = 0;
    while (i < N) {
        if (balls[i]) o_sum++;
        else z_sum++;
        do {
            i++;
        } while (i < N && balls[i - 1] == balls[i]);
    }

    cout << min(z_sum, o_sum) << '\n';

    while (Q--) {
        if (N == 1) {
            cout << "0\n";
            continue;
        }

        int p;
        cin >> p;
        p--;
        if (!p) {
            if (balls[p + 1]) {
                z_sum += (balls[p] ? 1 : -1);
            } else {
                o_sum += (balls[p] ? -1 : 1);
            }
        }
        else if (p == N - 1) {
            if (balls[p - 1]) {
                z_sum += (balls[p] ? 1 : -1);
            } else {
                o_sum += (balls[p] ? -1 : 1);
            }
        }
        else if (balls[p - 1] == balls[p + 1]) {
            if (balls[p - 1] == balls[p]) {
                z_sum++;
                o_sum++;
            } else {
                z_sum--;
                o_sum--;
            }
        }

        balls[p] = !balls[p];

        cout << min(z_sum, o_sum) << '\n';
    }
}
