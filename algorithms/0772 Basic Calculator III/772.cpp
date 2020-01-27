#include "../header.h"

class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }
        vector<string> sp = split(s);
        stack<string> ss;
        vector<string> nl;
        for (int i = 0; i < sp.size(); ++i) {
            if (sp[i][0] >= '0' && sp[i][0] <= '9' || (sp[i].length() > 1 && sp[i][1] >= '0' && sp[i][1] <= '9')) {
                nl.push_back(sp[i]);
            }
            else if (sp[i] == "(") {
                ss.push(sp[i]);
            }
            else if (sp[i] == ")") {
                while (ss.size() && ss.top() != "(") {
                    nl.push_back(ss.top());
                    ss.pop();
                }
                ss.pop();
            }
            else {
                if (sp[i] == "+" || sp[i] == "-") {
                    while (ss.size() && ss.top() != "(") {
                        nl.push_back(ss.top());
                        ss.pop();
                    }
                }
                else {
                    while (ss.size() && ss.top() != "(" && ss.top() != "+" && ss.top() != "-") {
                        nl.push_back(ss.top());
                        ss.pop();
                    }
                }
                ss.push(sp[i]);
            }
        }
        while (ss.size()) {
            nl.push_back(ss.top());
            ss.pop();
        }
        stack<long> res;
        for (int i = 0; i < nl.size(); ++i) {
            if (nl[i][0] >= '0' && nl[i][0] <= '9' || (nl[i].length() > 1 && nl[i][1] >= '0' && nl[i][1] <= '9')) {
                res.push(stol(nl[i]));
            }
            else {
                int b = res.top();
                res.pop();
                int a = res.top();
                res.pop();
                if (nl[i] == "+") {
                    a += b;
                    res.push(a);
                }
                else if (nl[i] == "-") {
                    a -= b;
                    res.push(a);
                }
                else if (nl[i] == "*") {
                    a *= b;
                    res.push(a);
                }
                else if (nl[i] == "/") {
                    a /= b;
                    res.push(a);
                }
            }
        }
        return res.top();
    }
    
    vector<string> split(string str) {
        vector<string> res;
        string temp = "";
        int n = str.length();
        for (int i = 0; i < n; ++i) {
            if (str[i] == ' ') {
                if (temp.length()) {
                    if (res.size() && res.back() == "-") {
                        if (res.size() >= 2 && !(res[res.size() - 2][0] >= '0' && res[res.size() - 2][0] <= '9' || res[res.size() - 2] == ")")) {
                            temp = "-" + temp;
                            res.pop_back();
                        }
                        else if (res.size() == 1) {
                            temp = "-" + temp;
                            res.pop_back();
                        }
                    }
                    res.push_back(temp);
                    temp = "";
                }
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')') {
                if (temp.length()) {
                    if (res.size() && res.back() == "-") {
                        if (res.size() >= 2 && !(res[res.size() - 2][0] >= '0' && res[res.size() - 2][0] <= '9' || res[res.size() - 2] == ")")) {
                            temp = "-" + temp;
                            res.pop_back();
                        }
                        else if (res.size() == 1) {
                            temp = "-" + temp;
                            res.pop_back();
                        }
                    }
                    res.push_back(temp);
                }
                temp = "";
                switch (str[i]) {
                    case '+':
                        res.push_back("+");
                        break;
                    case '-':
                        res.push_back("-");
                        break;
                    case '*':
                        res.push_back("*");
                        break;
                    case '/':
                        res.push_back("/");
                        break;
                    case '(':
                        res.push_back("(");
                        break;
                    case ')':
                        res.push_back(")");
                        break;
                }
            }
            else {
                temp += str[i];
            }
        }
        if (temp.length()) {
            if (res.size() && res.back() == "-") {
                if (res.size() >= 2 && !(res[res.size() - 2][0] >= '0' && res[res.size() - 2][0] <= '9' || res[res.size() - 2] == ")")) {
                    temp = "-" + temp;
                    res.pop_back();
                }
                else if (res.size() == 1) {
                    temp = "-" + temp;
                    res.pop_back();
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
    return  0;
}