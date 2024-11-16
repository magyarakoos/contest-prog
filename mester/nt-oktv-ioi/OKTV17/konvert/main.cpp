#include <bits/stdc++.h>
using namespace std;

// Define operator precedence and associativity
string ops = "+-*/";
map<char, int> prec{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;
    stack<pair<string, int>> st; // {expression, precedence}

    for (char c : s) {
        if (ops.find(c) == string::npos) {
            st.push({string(1, c), 3});
        } else {
            auto right = st.top();
            st.pop();
            auto left = st.top();
            st.pop();

            string result;
            if (left.second < prec[c]) {
                result += '(' + left.first + ')';
            } else {
                result += left.first;
            }
            result += c;
            if (right.second < prec[c] ||
                (right.second == prec[c] &&
                 (c == '-' || c == '/'))) {
                // Add parentheses for right operand if:
                // 1. Its precedence is less than the
                // current operator.
                // 2. It has equal precedence but is part of
                // a non-commutative operator.
                result += '(' + right.first + ')';
            } else {
                result += right.first;
            }

            st.push({result, prec[c]});
        }
    }
    cout << st.top().first << "\n";
}
