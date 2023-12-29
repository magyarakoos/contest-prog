#include <iostream>
#include <vector>
using namespace std;

void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
}

int main() {
    init();

    int N, max_g;
    cin >> N;
    int G[N];
    for (int i = 0; i < N; i++) {
        cin >> G[i];
        max_g = max(max_g, G[i]);
    }

    vector<int> idS;

    for (int i = 0; i < N; i++) {
        if (G[i] == max_g) {
            idS.push_back(i + 1);
        }
    }

    cout << max_g << '\n' << idS.size() << '\n';

    for (int id : idS) cout << id << '\n';
}
