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
    Token(string _a, string _b, string _op, int _prec) : a(_a), b(_b), op(_op), precedence(_prec) {}
    string to_string() const {
        return '(' + a + op + b + ')';
    }
};

Token combine(Token a, Token b, string op, int prec) {
    return Token(a.to_string(), b.to_string(), op, prec);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    const string ar = "+-*/";
    map<char, int> precS {
        {'+', 2},
        {'-', 2},
        {'*', 1},
        {'/', 1}
    };
    stack<Token> st;

    for (char c : s) {
        if (ar.find(c) != ar.npos) {
            Token b = st.top(); st.pop();
            Token a = st.top(); st.pop();
            st.push();
        } else {
            st.push(string(1, c));
        }
    }

    cout << st.top().to_string() << "\n";
}