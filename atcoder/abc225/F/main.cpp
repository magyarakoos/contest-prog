#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[j - 1] + a[j] >= a[j] + a[j - 1]) { swap(a[j - 1], a[j]); }
        }
    }

    while (N > K) a.pop_back(), N--;

    DB(a);
}
