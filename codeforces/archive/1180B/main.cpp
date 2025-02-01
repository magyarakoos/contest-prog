#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> posS, negS;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 0)
            posS.push_back(x);
        else
            negS.push_back(x);
    }
    sort(posS.begin(), posS.end());
    sort(negS.begin(), negS.end());
}
