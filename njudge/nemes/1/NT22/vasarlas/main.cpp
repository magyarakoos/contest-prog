#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N), prefA(N), prefB(N);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    partial_sum(all(A), prefA.begin());
    partial_sum(all(B), prefB.begin());

    for (int x : prefA) cout << x << " ";
}
