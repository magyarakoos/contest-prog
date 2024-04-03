#include <bits/stdc++.h>
using namespace std;

ifstream fin("minta(1)/be2.txt");
#define cin fin

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    int l = 0, r = 1, result = -1, result_i = -1;
    while (r < N) {
        if (v[l] < v[r]) {
            result = max(result, r - l);
            
            l = r;
        }
        r++;
    }

    cout << result;
}