#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> Bal(N), Jobb(N);
    for (int& e : Bal) cin >> e;
    


    vector<vector<array<int, 2>>> g(2 * N + 1);
}