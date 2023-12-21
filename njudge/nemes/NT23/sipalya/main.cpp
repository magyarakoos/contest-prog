#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using ll = unsigned long long;
#define speed cin.tie(0); ios::sync_with_stdio(0)

vector<ll> heightS;
int N, K;

ll window(int i) {
    ll cost = 0;
    cout << 0;
    return 0;
    cout << heightS[i] << ' ';
    for (int j = i + 1; j < i + K; j++) {
        cout << heightS[j] << ' ';
    }
    cout << '\n';
    return cost;
}

int main() {
    speed;

    heightS.resize(N);
    for (ll& h : heightS) cin >> h;

    ll result = LLONG_MAX;

    for (int i = 0; i <= N - K; i++) {
        window(i);
    }
}
