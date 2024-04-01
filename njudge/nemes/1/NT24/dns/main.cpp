#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    int result = 0, before_g = 0, after_g = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') after_g++;
        if (s[i] == 'G') {
            before_g += after_g;
            after_g = 0;
        }
        if (s[i] == 'T') {
            result += before_g;
        }
    }

    cout << result;
}
