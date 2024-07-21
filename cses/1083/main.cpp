#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> h(N--);
    while (N--) {
        int x;
        cin >> x;
        h[x - 1] = 1;
    }
    for (int i = 0;; i++) {
        if (!h[i]) cout << i + 1, exit(0);
    }
}
