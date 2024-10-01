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

        auto f = [&](int x) -> bool { return; };

        int l = -1, r = lis.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (f(m)) {
                r = m;
            } else {
                l = m;
            }
        }
    }
}
