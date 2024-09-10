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
            if (s[j - 1] + s[j] >= s[j] + s[j - 1]) { swap(s[j - 1], s[j]); }
        }
    }
}
