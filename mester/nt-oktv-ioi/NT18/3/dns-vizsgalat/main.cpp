#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

bool window(int x, const string& s) {

    int left = 0, right = x - 1;

    for (;right < size(s); left++, right++) {

        char hash = 0;

        for (int i = right; i <= left; i++) {
            if (s[i] == 'A') {
                hash |= 1;
            }
            else if (s[i] == 'C') {
                hash |= (1 << 1);
            }
            else if (s[i] == 'G') {
                hash |= (1 << 2);
            }
            else if (s[i] == 'T') {
                hash |= (1 << 3);
            }
        }

        if (hash != ())
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int N = size(s);

    if (N < 4) {
        cout << N;
        exit(0);
    }

    for (int i = 4; i < N; i++) {
        if (window(i, s)) {
            cout << i;
            exit(0);
        }
    }
}