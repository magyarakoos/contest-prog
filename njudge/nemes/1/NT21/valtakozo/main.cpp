#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    string s;
    cin >> s;
    int N = s.size(), A[26] = {0};
    for (char c : s) A[c - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (N / 2 + (N & 1) < A[i]) {
            cout << -1;
            exit(0);
        }
    }

    for (int i = 0, j, last = 0; i < N; i++) {
        j = -1;
        for (int curr = 25; curr >= 0; curr--) {
            if (curr == last || A[curr] == 0) continue;

            j = curr;
            
            if ((N - i) & 1 && A[curr] == (N - i) / 2 + 1) break;            
        }
        last = j;
        A[j]--;
        cout << (char)(j + 'a');
    }
}
