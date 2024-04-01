#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    priority_queue<int> pq(v.begin(), v.end());
    bool a_turn = 1;
    ll A = 0, B = 0;
    while (!pq.empty()) {

        int val = v.


        a_turn ^= 1;
    }
}
