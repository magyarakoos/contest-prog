#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main() {
    map<ll, int> m;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        m[-A]++;
    }

    while (M--) {
        int B, C;
        cin >> B >> C;
        m[-C] += B;
    }

    ll result = 0;
    for (auto [key, value] : m) {
        if (value >= N) {
            result += N * -key;
            break;
        } else {
            result += value * -key;
            N -= value;
        }
    }

    cout << result << "\n";
}
