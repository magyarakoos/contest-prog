#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> lis;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        auto f = [&](int x) -> bool { return 0; };

        int l = -1, r = lis.size() - 1;
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
