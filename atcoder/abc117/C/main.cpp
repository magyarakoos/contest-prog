#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int& x : a) cin >> x;

    if (N >= M) {
        cout << 0;
        exit(0);
    }

    sort(a.begin(), a.end());

    priority_queue<array<int, 2>> pq;
    for (int i = 1; i < M; i++) {
        pq.push({a[i] - a[i - 1], i});
    }

    vector<bool> c(M);
    for (int i = 0; i < N - 1; i++) {
        c[pq.top()[1]] = 1;
        pq.pop();
    }

    long long result = 0;
    int lp = a[0];
    for (int i = 1; i < M; i++) {
        if (c[i]) {
            result += a[i - 1] - lp;
            lp = a[i];
        }
        else if (i + 1 == M) {
            result += a[i] - lp;
        }
    }

    cout << result;
}
