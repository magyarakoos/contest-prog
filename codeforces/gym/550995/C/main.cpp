#include <iostream>
#include <vector>

#include <debug.h>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> a;
    for (int x = 0; (1 << x) + P <= 5 * N; x++) { a.push_back((1 << x) + P); }
    int M = a.size();

    int result = INT_MAX;

    cout << (result == INT_MAX ? -1 : result);
}
