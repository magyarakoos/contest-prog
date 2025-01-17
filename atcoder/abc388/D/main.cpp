#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;

    multiset<int> adultS;
    for (int i = 0; i < N; i++) {
        adultS.insert(A[i]);
        while (!adultS.empty() && *adultS.begin() < i + 1) {
            adultS.erase(adultS.begin());
        }
    }
}
