#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

constexpr int MAXN = 2e5;

struct Vertex {

};

Vertex t[4 * MAXN + 1];



int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& e : A) cin >> e;


    while (Q--) {
        char type;
        cin >> type;
        if (type == '1') {
            int P, X;
            cin >> P >> X;
        } else {
            int L, R;
            cin >> L >> R;
        }
    }
}