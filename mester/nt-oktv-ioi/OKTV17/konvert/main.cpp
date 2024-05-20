#include <bits/stdc++.h>
using namespace std;

const string ar = "+-*/";
map<char, int> precS {
    {'+', 2},
    {'-', 2},
    {'*', 1},
    {'/', 1}
};

struct Token {
    string a;
    string b;
    string op;
    int precedence;
    Token() : a(""), b(""), op(""), precedence(0) {}
    Token(string s) : a(""), b(""), op(s), precedence(0) {}
    Token(string _a, string _b, string _op, int _prec) : a(_a), b(_b), op(_op), precedence(_prec) {}
    string to_string(bool par) const {
        return (par ? "(" : "") + a + op + b + (par ? ")" : "");
    }
};

Token combine(Token a, Token b, string op, int prec) {
    return Token(a.to_string(a.precedence > prec), b.to_string(b.precedence > prec), op, prec);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    stack<Token> st;

    for (char c : s) {
        if (ar.find(c) != ar.npos) {
            Token b = st.top(); st.pop();
            Token a = st.top(); st.pop();
            st.push(combine(a, b, string(1, c), precS[c]));
        } else {
            st.push({string(1, c)});
        }
    }

    cout << st.top().to_string(0) << "\n";
}