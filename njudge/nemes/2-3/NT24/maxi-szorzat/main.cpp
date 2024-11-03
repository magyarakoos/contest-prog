#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N, K, B;
    cin >> N >> K >> B;

    vector<ll> neg, pos;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
    }

    if (neg.size() < B) {
        cout << "-1\n";
        exit(0);
    }

    sort(neg.rbegin(), neg.rend());
    ll result = 1;
    for (int i = 0; i < B; i++) {
        result *= neg.back();
        neg.pop_back();
    }

    ll negsum = 0;
    for (int i = 0; i < neg.size(); i++) {
        negsum += -neg[i];
    }

    if (negsum > K) {
        cout << "-1\n";
        exit(0);
    }

    K -= negsum;
}
