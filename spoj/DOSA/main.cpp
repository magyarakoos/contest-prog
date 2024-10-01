#include <iostream>
using namespace std;

int N, result, prv, x;
int main() {
    cin >> N >> prv;
    while (--N) {
        cin >> x;
        if (x <= prv) {
            result++;
            prv++;
        } else {
            prv = x;
        }
    }
    cout << result;
}
