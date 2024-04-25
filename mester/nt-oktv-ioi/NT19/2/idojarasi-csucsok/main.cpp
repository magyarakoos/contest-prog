#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

    int M = size(tmpS);
    int ccnt = 0, hcnt = 0, l = 0, r = 0;
    ll result = 0;

    while (r < M) {
        if (ccnt == L && hcnt == K) {
            result += (sliceS[tmpS[l] - 1] + 1) * (sliceS[tmpS[r] + 1] + 1);
        }
    }
}