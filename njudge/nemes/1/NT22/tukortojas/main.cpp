#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    int N;
    cin >> N;
    vector<bool> A(N), B(N);
    
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        A[i] = c == 'F';
    }
    for (int i = 0; i < N; i++) {
        cin >> c;
        B[i] = c == 'F';
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
       count += (A[i] == B[i]) == (count & 1);
    }

    cout << count;
}
