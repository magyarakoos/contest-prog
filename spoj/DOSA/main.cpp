#include <iostream>
using namespace std;

int N, result, prv, x;
int main() {
    cin >> N >> prv;
    while (--N) {
        cin >> x;
        result += x <= prv;
        prv = x;
    }
    cout << result;
}
