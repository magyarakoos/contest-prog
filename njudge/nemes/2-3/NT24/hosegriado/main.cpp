#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)
using namespace std;

vector<int> v;

bool rsml(int i, int j, int F) {
    for (; i <= j; i++) {
        if (v[i] >= F) return 0;
    }
    return 1;
}

bool rbg(int i, int j, int F) {
    for (; i <= j; i++) {
        if (v[i] <= F) return 0;
    }
    return 1;
}

int main() {
    int N, K, L, F;
    cin >> N >> K >> L >> F;

    v.resize(N);
    for (int& x : v) cin >> x;

    int result = 0;
    bool alert = 0;
    for (int i = K - 1; i < N; i++) {
        if (!alert && rbg(i - K + 1, i, F)) {
            alert = 1;
            result++;
        }
        else if (0 <= i - L + 1 && alert && rsml(i - L + 1, i, F)) {
            alert = 0;
        }
    }

    cout << result;
}
