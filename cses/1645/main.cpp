#include <array>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    stack<array<int, 2>> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        while (!s.empty() && s.top()[0] >= x) s.pop();
        cout << (!s.empty() ? s.top()[1] + 1 : 0) << " ";
        s.push({x, i});
    }
    cout << "\n";
}
