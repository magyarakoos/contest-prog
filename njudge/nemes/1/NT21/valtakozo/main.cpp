#include <bits/stdc++.h>
using namespace std;

bool can_finish(const array<int, 26>& h, int j) {
    int sum = 0, mx = 0, mxi = -1;
    for (int i = 0; i < 26; i++) {
        sum += h[i];
        if (mx < h[i]) {
            mx = h[i];
            mxi = i;
        }
    }
    return mx <= sum / 2 + (sum % 2 != 0 && j != mxi);
}

int main() {
    string s;
    cin >> s;

    array<int, 26> h = {0};
    for (char c : s) h[c - 'a']++;

    string result;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            h[j]--;
            if (h[j] > 0 && can_finish(h, j) &&
                (result.empty() || result.back() != j + 'a')) {
                result += j + 'a';
                break;
            }
            h[j]++;
        }
    }

    cout << result;
}
