#include "../header.h"

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> ss;
//         int n = s.length();
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//                 ss.push(s[i]);
//             }
//             else {
//                 if (ss.size() == 0 || s[i] == ')' && ss.top() != '(' || s[i] == ']' && ss.top() != '[' || s[i] == '}' && ss.top() != '{') {
//                     return false;
//                 }
//                 ss.pop();
//             }
//         }
//         return ss.empty();
//     }
// };

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
                break;
            default:
                return false;
            }
        }
        return st.empty();
    }
};