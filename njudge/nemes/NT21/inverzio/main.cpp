#include <iostream>
#include <vector>
#include <array>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(false)

using point = array<int, 2>;

int main() {
    speed;

    int N;
    cin >> N;
    vector<int> v(N + 1);

    for (int i = 1, a; i <= N; i++) {
        cin >> a;
        v[a] = i;
    }

    int min_i = v[N];
    point p{0, 0};

    for (int i = N - 1; i > 0; i--) {
        if (v[i] < min_i) {
            min_i = v[i];
        } else {
            int diff = v[i] - min_i;
            if ((p[1] - p[0]) < diff) {
                p = { min_i, v[i] };
            }
        }
    }

    if (p[1] - p[0]) cout << p[0] << ' ' << p[1];
    else cout << -1;
}
