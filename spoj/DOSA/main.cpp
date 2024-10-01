#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<array<int, 2>> lis;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        auto it = lower_bound(lis.begin(), lis.end(), a - i);
    }

    cout << N - lis.size();
}
