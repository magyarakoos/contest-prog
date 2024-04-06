#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N, M;

vector<int> after(vector<int> v) {
    for (int i = M - 1 ; i >= 0; i--) {
        cout << i << " " << v[i] << " " << N - (M - i - 1) << "\n";
        if (v[i] < N - (M - i - 1)) {
            for (int j = i + 1; j < M; j++) {
                v[j] = v[i] + j - i;
            }
            break;
        }
    }
    // körbeértünk, lex-minimális lesz a megoldás
    for (int i = 0; i < M; i++) {
        v[i] = i + 1;
    }
    return v;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;
    vector<int> v(M);
    for (int& x : v) cin >> x;
    
    for (int x : after(v)) cout << x << " ";
    cout << "\n";
    
}