#include <iostream>
#include <vector>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int N;
vector<int> v;

int search(int t) {
    int b = 1, e = N, h, cmp;
    while (b <= e) {
        h = (e - b) / 2 + b;
        cmp = v[h - 1] < t && t <= v[h] ? 0 : v[h] < t ? 1 : -1;
        if (cmp == 1) {
            b = min(h + 1, N);
        }
        else if (cmp == -1) {
            e = max(h - 1, 0);
        }
        else {
            return h;
        }
    }
    return 0;
}

int main() {
    speed;

    int K, sum;
    cin >> N >> K;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    while (K--) {
        int t;
        cin >> t;
        t %= v[N];
        cout << search(t) << ' ';
    }
}
