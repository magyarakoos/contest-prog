#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;

    multiset<int> adultS;
    for (int i = 0; i < N; i++) {
        for (int x : adultS) cout << x << " ";
        cout << "\n";

        adultS.insert(A[i]);
        while (!adultS.empty() && *adultS.begin() < i + 1) {
            adultS.erase(adultS.begin());
        }
        adultS.insert(adultS.size());
    }
}
