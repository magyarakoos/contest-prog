#include <bits/stdc++.h>
using namespace std;
#define size(v) (int)v.size()

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, K, L;
    cin >> N >> K >> L;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    vector<int> sliceS, posS, tmpS;
    for (int i = 1; i < N - 1; i++) {
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            if (sliceS.empty()) {
                sliceS.push_back(i);
            } else {
                sliceS.push_back(i - posS.back() - 1);
            }
            sliceS.push_back(-2);
            posS.push_back(i);
            posS.push_back(i);
            tmpS.push_back(size(sliceS) - 1);
        }
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            if (sliceS.empty()) {
                sliceS.push_back(i);
            } else {
                sliceS.push_back(i - posS.back() - 1);
            }
            sliceS.push_back(-1);
            posS.push_back(i);
            posS.push_back(i);
            tmpS.push_back(size(sliceS) - 1);
        }
    }
    sliceS.push_back(N - posS.back() - 1);
    posS.push_back(N);
    for (int i = 0; i < size(sliceS); i++) {
        cout << sliceS[i] << " " << posS[i] << "\n";
    }
}