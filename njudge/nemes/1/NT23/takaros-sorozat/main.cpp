#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), po(N), sz(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        po[i] = (a[i] = c == '1');
    }
}
