#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int& x : a) cin >> x;
    for (int i = 1; i <= N; i++) {
        cout << *lower_bound(a.begin(), a.end(), i) - i << "\n";
    }
}
