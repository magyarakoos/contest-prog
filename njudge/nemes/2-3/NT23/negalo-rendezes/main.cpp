#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
    int N;
    cin >> N;
    map<int, int> A;
    for (int i = 0; i < N; i++) {
        int Ai;
        cin >> Ai;
        A[Ai]++;
    }
    int i = 0;
    ll result = 1;
    for (auto entry : A) {
        if (i) {
            result = result * ++entry.second % 1'000'000'007;
        } else i++;
    }
    cout << result;
}
