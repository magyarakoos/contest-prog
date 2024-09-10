#include <bits/stdc++.h>
using namespace std;

vector<int> h;

int f(int l, int r) {
    if (l > r) return 0;
    if (l == r) return h[l];
    int mni = min_element(h.begin() + l, h.begin() + r + 1) - h.begin();
    int result = h[mni];
    for (int i = l; i <= r; i++) h[i] -= result;
    return result + f(l, mni - 1) + f(mni + 1, r);
}

int main() {
    int N;
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    cout << f(0, N - 1);
}
