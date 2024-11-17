#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;
    int result = 0, mn = 1e9;
    for (int i = N - 1; i >= 0; i--) {
        mn = min(mn, A[i]);
        result += mn;
    }
    cout << result << "\n";
}
