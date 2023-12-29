#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

const int N_lengthS[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int S_lengthS[13] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int days(int e, int h, int n) {
    for (int i = 1; i < e; i++) {
        n += (i % 4 ? 365 : 366);
    }
    if (e % 4) {
        for (int i = 1; i < h; i++) {
            n += N_lengthS[i];
        }
    } else {
        for (int i = 1; i < h; i++) {
            n += S_lengthS[i];
        }
    }
    return n;
}

int main() {
    speed;

    int M, E, H, N, D, result = 0;
    cin >> M >> E >> H >> N;
    
    D = days(E, H, N);

    while (M--) {
        int FE, FH, FN;
        cin >> FE >> FH >> FN;

        if (FE == E) {
            result++;
            continue;
        }

        if (abs(FE - E) == 1) {
            result += (abs(days(FE, FH, FN) - D) <= 365);
        }

    }

    cout << result;
}
