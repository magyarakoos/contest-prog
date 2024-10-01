#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    map<int, int> m;
    int N, M;
    cin >> N >> M;

    while (N--) {
        int A;
        cin >> A;
        m[-A]++;
    }

    while (M--) {
        int B, C;
        m[-C] += B;
    }

    int result = 0;
    for (auto [key, value] : m) {
        if (value >= N) {
            result += N * -key;
        } else {
            result += value * -key;
            N -= value;
        }
    }

    cout << result << "\n";
}
