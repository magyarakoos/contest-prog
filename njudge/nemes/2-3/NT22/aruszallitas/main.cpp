#include <iostream>
#include <map>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int main() {
    speed;
    
    int N, M;
    cin >> N >> M;
    map<int, int> from;

    while (M--) {
        int E, V;
        cin >> E >> V;
        from[E] = max(from[E], V);
    }
    from[N] = N;

    int result = 0, pos = 1;

    for (auto [e, v] : from) {
        if (pos >= N) break;
        if (pos < e) result++;
        pos = max(pos, v);
    }

    cout << result;
}
