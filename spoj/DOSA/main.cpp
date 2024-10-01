#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<array<int, 2>> lis;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        auto f = [&](int x) -> bool {
            return i - lis[x][1] <= a - lis[x][0];
        };

        int l = -1, r = lis.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (f(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        if (r == lis.size()) {
            lis.push_back({a, i});
        } else {
            lis[r] = {a, i};
        }
    }
}
