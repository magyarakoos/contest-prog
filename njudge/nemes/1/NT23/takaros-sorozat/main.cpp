#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), ps(N + 1);
    for (int& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), ps.begin() + 1);
}
