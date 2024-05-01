#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> kidS(N);
    vector<int> capS(M);
    for (auto& [a, b] : kidS) cin >> a >> b;
    for (int& x : capS) cin >> x;
    cout << "YAP;";
}