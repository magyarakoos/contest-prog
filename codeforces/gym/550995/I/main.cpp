#include <iostream>
using namespace std;

int intvS = 100;

int a[] = {

};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        K--;
        int p = a[K / intvS], mod = K % intvS;
        for (int i = p + 1;; i++) {}
    }
}
