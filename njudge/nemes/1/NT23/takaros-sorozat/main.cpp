#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N;
    cin >> N;
    vector<bool> v;

    bool start = 0;
    while (N--) {
        char c;
        cin >> c;
        start |= c == '1';
        if (start) {
            v.push_back(c == '1');
        }
    }

    N = v.size();

    int result = 0;
    auto p1v = v;

    for (int i = 0; i < N; i++) {
        if (!p1v[i]) {
            result++;
            if (i + 1 < N) p1v[i + 1] = 1;
        }
    }

    cout << result << '\n';

    result = 0;
    for (int i = 0; i < N; i++) {
        if (!v[i]) {
            result++;
            for (int j = i + 1; j < N && j < i + 4; j++) {
                v[j] = 1;
            }
        }
    }

    cout << result;
}
