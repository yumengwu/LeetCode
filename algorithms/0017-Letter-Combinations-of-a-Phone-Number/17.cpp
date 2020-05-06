#include "../header.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        string m[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        list<char> temp;
        helper(digits, 0, res, temp, m);
        return res;
    }
    
    void helper(string& s, int idx, vector<string>& res, list<char>& temp, string* m) {
        if (idx == s.length()) {
            string str = "";
            for (char c : temp) {
                str += c;
            }
            res.push_back(str);
            return;
        }
        for (int i = 0; i < m[s[idx] - '2'].length(); ++i) {
            temp.push_back(m[s[idx] - '2'][i]);
            helper(s, idx + 1, res, temp, m);
            temp.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> res;
//         if (digits.length() == 0) {
//             return res;
//         }
//         vector<vector<char>> v{{}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
//         vector<vector<char>> temp;
//         for (int i = 0; i < digits.length(); ++i) {
//             temp.push_back(v[digits[i] - '1']);
//         }
//         vector<char> vc;
//         helper(temp, res, vc, 0);
//         return res;
//     }
//     void helper(vector<vector<char>> & temp, vector<string> & res, vector<char> & vc, int index) {
//         if (index == temp.size()) {
//             char * s = new char[vc.size() + 1];
//             for (int i = 0; i < vc.size(); ++i) {
//                 s[i] = vc[i];
//             }
//             s[vc.size()] = 0;
//             res.push_back(s);
//             delete [] s;
//             return;
//         }
//         for (int i = 0; i < temp[index].size(); ++i) {
//             vc.push_back(temp[index][i]);
//             helper(temp, res, vc, index + 1);
//             vc.pop_back();
//         }
//     }
// };

int main()
{
    Solution s;
    vector<string> res = s.letterCombinations("2345");
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}
