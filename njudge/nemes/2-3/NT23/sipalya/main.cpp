#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using ll = unsigned long long;
#define speed cin.tie(0); ios::sync_with_stdio(0)

vector<ll> heightS;
int N, K;

ll window(int i) {
    ll cost = 0, mx = 0;

    for (int j = i; j < i + K; j++) {
        mx = max(mx, heightS[j]);
    }

    for (int j = i; j < i + K; j++) {
        cost += mx - heightS[j];
    }

    return cost;
}

int main() {
    speed;

    cin >> N >> K;

    heightS.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> heightS[i];
        heightS[i] += i;
    }

    ll result = LLONG_MAX;

    for (int i = 0; i <= N - K; i++) {
        result = min(result, window(i));
    }

    cout << result;
}
