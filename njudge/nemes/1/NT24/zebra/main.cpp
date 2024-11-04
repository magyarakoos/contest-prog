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

    vector<int> dp(N + 1, 2e9);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        array<int, 2> cnt = {0, 0};
        int curr = 0;
        for (int j = i; j >= 0; j--) {
            cnt[a[j][1]]++;
            curr += a[j][0] if (cnt[0] && cnt[1]) {}
        }
    }
}
