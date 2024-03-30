#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N, K, Q;
vector<int> p;
vector<vector<bool>> v;

void case2() {
    for (int i = 0; i < Q; i++) {

        


        cout << "0" << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> K >> Q;
    
    p.resize(N);
    for (int i = 1; i < N; i++) {
        cin >> p[i];
    }

    v.assign(Q, vector<bool>(N));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            v[i][j] = c == '1';
        }
    }

    if (all_of(p.begin() + 2, p.end(), [](int x){ return x == 2; })) {
        case2();
        exit(0);
    }

    assert(1 == 0);
}