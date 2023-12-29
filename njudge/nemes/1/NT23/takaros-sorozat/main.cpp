#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    //speed;

    bool done = 0;
    int N, fo = -1;
    char c;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> c;
        if (!done) {
            if (c == '1') {
                fo = i;
                done = 1;
            }
        }
    }

    if (fo <= 0) {
        cout << "0\n0";
        exit(0);
    }

    int len = N - fo - 1;
    cout << len / 2 + (len & 1) << '\n' << len / 4 + (len % 4) / 2 + ((len % 4) & 1);
}
