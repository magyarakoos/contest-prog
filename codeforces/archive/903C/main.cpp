#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    unordered_map<int, int> m;

    int result = 0;

    while (N--) {
        int a;
        cin >> a;
        result = max(result, ++m[a]);
    }

    cout << result;
}