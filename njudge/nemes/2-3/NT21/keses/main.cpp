#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int main() {
    speed;
    int N;
    cin >> N;
    vector<int> v(N);
    set<int> s, t;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        t.insert(v[i]);
        if (t.size() == s.size()) {
            cout << i + 1;
            exit(0);
        }
    }
}
