#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)
using namespace std;

vector<int> heightS, cache;
int hs;

int height(int node) {
    if (node * 2 + 1 >= hs) {
        cache[node] = 0;
        return 0;
    }

    if (cache[node] == -1) {
        cache[node] = max(
            height(node * 2) + heightS[node * 2],
            height(node * 2 + 1) + heightS[node * 2 + 1]
        );
    }

    return cache[node];
}

int main() {
    speed;

    int N, M;
    cin >> N >> M;

    hs = (1 << N);

    heightS.assign(hs, 1);
    cache.assign(hs, -1);
    heightS[0] = 0;
    cache[0] = 0;

    while (M--) {
        int C, H;
        cin >> C >> H;
        heightS[C] = H;

        for (int i = C; i > 0; i /= 2) {
            cache[i] = -1;
        }

        cout << height(1) << '\n';
    }
}
