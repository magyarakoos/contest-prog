#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K, db;
    cin >> N >> K;
    while (N--) {
        char c;
        cin >> c;
        db += c == '1';
    }
    int curr = 2;
    ll result = 0;
    while (curr <= db) {
        result += db - ++curr;
    }
    cout << result;
}
