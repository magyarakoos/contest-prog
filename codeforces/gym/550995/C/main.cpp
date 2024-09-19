#include <iostream>
#include <vector>

#include <debug.h>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> a;
    for (int x = 0; (1 << x) + P <= N; x++) { a.push_back((1 << x) + P); }

    int result = 0;

    for (int i = a.size() - 1; ~i && N > 0; i--) {
        if (a[i] <= N) N -= a[i], result++;
    }

    cout << (N ? -1 : result);
}
