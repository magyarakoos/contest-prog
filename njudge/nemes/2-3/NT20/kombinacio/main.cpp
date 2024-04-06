// O(M)
#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> after(vector<int> v) {
    for (int i = M - 1 ; i >= 0; i--) {
        if (v[i] < N - (M - i - 1)) {
            v[i]++;
            for (int j = i + 1; j < M; j++) {
                v[j] = v[i] + j - i;
            }
            return v;
        }
    }
    for (int i = 0; i < M; i++) {
        v[i] = i + 1;
    }
    return v;
}

vector<int> before(vector<int> v) {
    for (int i = M - 1 ; i > 0; i--) {
        if (v[i - 1] + 1 < v[i]) {
            v[i]--;
            for (int j = i + 1; j < M; j++) {
                v[j] = N - (M - j - 1);
            }

            return v;
        }
    }
    if (v[0] > 1) {
        v[0]--;
        for (int j = 1; j < M; j++) {
            v[j] = N - (M - j - 1);
        }
    } else {
        for (int i = 0; i < N; i++) {
            v[i] += N - M;
        }
    }
    return v;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;
    vector<int> v(M);
    for (int& x : v) cin >> x;
    
    for (int x : before(v)) cout << x << " ";
    cout << "\n";
    for (int x : after(v)) cout << x << " ";
    cout << "\n";
}