#include "../header.h"

class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }
        vector<string> v = split(s), res;
        stack<string> s2;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i][0] >= '0' && v[i][0] <= '9') {
                res.push_back(v[i]);
            }
            else {
                if (v[i] == "+" || v[i] == "-") {
                    while (s2.size()) {
                        res.push_back(s2.top());
                        s2.pop();
                    }
                    s2.push(v[i]);
                }
                else {
                    while (s2.size() && (s2.top() == "*" || s2.top() == "/")) {
                        res.push_back(s2.top());
                        s2.pop();
                    }
                    s2.push(v[i]);
                }
            }
        }
        while (s2.size()) {
            res.push_back(s2.top());
            s2.pop();
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i][0] >= '0' && res[i][0] <= '9') {
                s2.push(res[i]);
            }
            else {
                int b = stoi(s2.top());
                s2.pop();
                int a = stoi(s2.top());
                s2.pop();
                if (res[i] == "+") {
                    s2.push(to_string(a + b));
                }
                else if (res[i] == "-") {
                    s2.push(to_string(a - b));
                }
                else if (res[i] == "*") {
                    s2.push(to_string(a * b));
                }
                else {
                    s2.push(to_string(a / b));
                }
            }
        }
        return stoi(s2.top());
    }
    
    vector<string> split(string s) {
        int n = s.length();
        vector<string> v;
        string temp = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (temp.length()) {
                    v.push_back(temp);
                    temp = "";
                }
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (temp.length()) {
                    v.push_back(temp);
                    temp = "";
                }
                temp += s[i];
                v.push_back(temp);
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        if (temp.length()) {
            v.push_back(temp);
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<string> v = s.split("3+2*2");
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    return 0;
}