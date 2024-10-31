#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int LIM = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, sum = 0;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        sum += P[i];
    }
    
    const int prod = N * K;

    sort(P.begin(), P.end());
    
    if (prod == sum) {
        cout << 0 << endl;
    } else if (N == 1) {
        cout << 1 << endl;
    } else if (N == 2) {
        if (prod > max(P[0], P[1]) + LIM || prod < min(P[0], P[1]) + 1) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    } else if (prod > sum) {
        for (int i = 0, result = 0; i < N; i++) {
            sum += LIM - P[i];
            result++;
            if (prod <= sum) {
                cout << result << endl;
                return 0;
            }
        }
    } else {
        for (int i = N - 1, result = 0; i >= 0; i--) {
            sum -= P[i] - 1;
            result++;
            if (prod >= sum) {
                cout << result << endl;
                return 0;
            }
        }
    }
}
