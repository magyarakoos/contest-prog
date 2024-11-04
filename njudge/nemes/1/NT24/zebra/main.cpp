#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<array<int, 2>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][1];
    for (int i = 1; i <= N; i++) cin >> a[i][0];
    sort(a.begin(), a.end());

    vector<int> dp(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {}
    }
}
