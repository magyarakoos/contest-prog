#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int MAXT = 5e4;

struct Guy {
    int i;
    int K;
    int T;
    bool operator()(Guy A, Guy B) {
        if (A.T > B.T) return 1;
        if (A.T < B.T) return 0;
        if (A.K > B.K) return 1;
        if (A.K < B.K) return 0;
        return A.i > B.i;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<Guy> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].K >> v[i].T;
        v[i].i = i;
    }

    vector<Guy*> order(MAXT);

    for (int i = 1; i < MAXT; i++) {
        
    }
}
