#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lis;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            lis[it - lis.begin()] = x;
        }
    }
    cout << lis.size();
}
