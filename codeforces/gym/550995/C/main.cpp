#include <iostream>
#include <vector>

#include <debug.h>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> a;
    for (int x = 0; (1 << x) + P <= N; x++) { a.push_back((1 << x) + P); }
    int M = a.size();

    for (int mask = 0; mask < (1 << M); mask++) {}
}