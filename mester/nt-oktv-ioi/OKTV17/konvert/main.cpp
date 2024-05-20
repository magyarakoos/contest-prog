#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

struct Token {
    string a;
    string b;
    string op;
    int precedence;
    Token() : a(""), b(""), op(""), precedence(-1) {}
    Token(string s) : a(""), b(""), op(s), precedence(-1) {}
    Token operator +(Token t) {
        
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    stack<Token> st;

    for (char c : s) {
        string ar = "+-*/";
        if (ar.find(c) != ar.npos) {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push('(' + a + c + b + ')');
        } else {
            st.push(string(1, c));
        }
    }

    cout << st.top() << "\n";
}