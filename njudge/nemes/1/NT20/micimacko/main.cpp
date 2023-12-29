#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;
    int Y, X, K, N;
    cin >> Y >> X >> K >> N;
    cout << max((max(K - Y, 0) + N) - (X - Y), 0);
}
