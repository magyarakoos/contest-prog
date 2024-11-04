#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> d(K);
    vector<deque<int>> personS(K);

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        personS[C - 1].push_back(i);
    }
}
