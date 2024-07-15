#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> a(N), b(M);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, result = 0;
    while (i < N && j < M) {
        if (abs(a[i] - b[j]) <= K) {
            result++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << result << "\n";
}
