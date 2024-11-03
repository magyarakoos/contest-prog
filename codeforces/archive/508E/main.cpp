#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 610;

int p[MAXN], l[MAXN], r[MAXN];
int main() {
    int N;
    cin >> N;
    stack<int> st;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        st.push(i);
        p[i] = s.length();
        s += '(';
        while (!st.empty() &&
               p[st.top()] + l[st.top()] <= s.length()) {
            if (p[st.top()] + r[st.top()] < s.length()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            s += ')';
            st.pop();
        }
    }
    if (!st.empty())
        cout << "IMPOSSIBLE" << endl;
    else
        cout << s << endl;
}
