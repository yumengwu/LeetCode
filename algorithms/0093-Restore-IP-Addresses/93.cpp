#include "../header.h"

// class Solution {
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> res;
//         if (s.length() < 4) {
//             return res;
//         }
//         for (int a = 1; a < 4; ++a) {
//             for (int b = 1; b < 4; ++b) {
//                 for (int c = 1; c < 4; ++c) {
//                     for (int d = 1; d < 4; ++d) {
//                         if (a + b + c + d == s.size()) {
//                             int A = stoi(s.substr(0, a));
//                             int B = stoi(s.substr(a, b));
//                             int C = stoi(s.substr(a + b, c));
//                             int D = stoi(s.substr(a + b + c, d));
//                             if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
//                                 string temp = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
//                                 if (temp.size() == s.size() + 3) {
//                                     res.push_back(temp);
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        set<string> temp = helper(s, 4);
        vector<string> v(temp.begin(), temp.end());
        return v;
    }
    
    set<string> helper(string s, int k) {
        set<string> res;
        if (k == 1) {
            if (s.length() && s.length() < 4 && stoi(s) < 256 && (s.length() == 1 || s[0] != '0')) {
                res.insert(to_string(stoi(s)));
            }
            return res;
        }
        for (int i = 0; i < s.length() && i < 3; ++i) {
            string cur = s.substr(0, i + 1);
            if (cur.length() > 1 && cur[0] == '0') {
                break;
            }
            string str = to_string(stoi(cur));
            if (str.length() < 3 || stoi(str) < 256) {
                set<string> temp = helper(s.substr(i + 1), k - 1);
                if (temp.size()) {
                    for (string ss : temp) {
                        string ns = str + ".";
                        ns += ss;
                        res.insert(ns);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> v = s.restoreIpAddresses("0279245587303");
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<endl;
    }
    return 0;
}