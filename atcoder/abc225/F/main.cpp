#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;
    sort(a.begin(), a.end(),
         [](const string& s, const string& t) { return s + t > t + s; });

    bool swapped = 0;
    do {
        for (int j = 1; j < N; j++) {
            if (a[j - 1] + a[j] >= a[j] + a[j - 1]) {
                swap(a[j - 1], a[j]);
                swapped = 1;
            }
        }
    } while (swapped);
}
