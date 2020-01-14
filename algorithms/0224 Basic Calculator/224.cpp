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
            if (sp[i][0] >= '0' && sp[i][0] <= '9') {
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
                while (ss.size() && ss.top() != "(") {
                    nl.push_back(ss.top());
                    ss.pop();
                }
                ss.push(sp[i]);
            }
        }
        while (ss.size()) {
            nl.push_back(ss.top());
            ss.pop();
        }
        stack<int> res;
        for (int i = 0; i < nl.size(); ++i) {
            if (nl[i][0] >= '0' && nl[i][0] <= '9') {
                res.push(stoi(nl[i]));
            }
            else {
                int b = res.top();
                res.pop();
                int a = res.top();
                res.pop();
                if (nl[i] == "+") {
                    res.push(a + b);
                }
                else {
                    res.push(a - b);
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
                    res.push_back(temp);
                    temp = "";
                }
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')') {
                if (temp.length()) {
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
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.calculate("(1+12-3)-22+(14-(21-10))+5")<<endl;
    // for (int i = 0; i < v.size(); ++i) {
    //     cout<<v[i]<<endl;
    // }
    return 0;
}