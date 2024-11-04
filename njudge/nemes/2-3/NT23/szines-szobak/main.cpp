#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> d(K + 1);
    vector<deque<int>> personS(K + 1);

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        personS[C].push_back(i);
    }

    int result = 0;
    while (M--) {
        int C, X;
        cin >> C >> X;
        d[C] += X;
        while () }
}
