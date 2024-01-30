#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    while (N--) {
        cin >> v[N];
    }
    sort(v.begin(), v.end());
    int result = 1;
    for (int i = 1; i < v.size(); i++) {
        result += v[i - 1] != v[i];
    }
    cout << result;
}
