#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int A, B, C;
    map<int, vector<int>> m;
    while (A--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }
    while (B--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }
    while (C--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }

}