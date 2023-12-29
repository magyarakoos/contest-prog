#include <iostream>
#include <vector>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int N, K;
vector<int> v;

bool locally_high(int i) {
    for (int j = 1; j <= K; j++) {
        if ((i - j >= 0 ? v[i] < v[i - j] : 0) || (i + j < N ? v[i] < v[i + j] : 0)) 
            return 0;
    }
    return 1;
}

int main() {
    speed;

    cin >> N >> K;
    v.resize(N);
    
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) {
        if (locally_high(i)) {
            cout << i + 1;
            exit(0);
        }
    }

    cout << -1;
}
