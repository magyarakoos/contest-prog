#include <iostream>
#include <vector>
using namespace std;

int N, _, mx;
int main() {
    cin >> N;
    vector<int> v(N), result;
    for (int& x : v) cin >> x >> _;
    mx = v[0];

    for (int i = 1; i < N; i++) {
        if (mx < v[i]) result.push_back(i + 1);
        mx = max(mx, v[i]);
    }

    cout << result.size() << ' ';
    for (int x : result) cout << x << ' ';
    cout << endl;
}