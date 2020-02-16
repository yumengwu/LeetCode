#include "../header.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) {
            return s;
        }
        while (1) {
            string ns = helper(s, k);
            if (ns == s) {
                return ns;
            }
            s = ns;
        }
    }
    
    string helper(string s, int k) {
        char temp[s.length() + 1] = {0};
        int idx = 0, i = 0;
        while (i < s.length()) {
            int j = i + 1;
            while (j < s.length() && s[j] == s[j - 1] && j - i < k) ++j;
            if (j - i < k) {
                while (i < j) temp[idx++] = s[i++];
            }
            else {
                i = j;
            }
        }
        string res(temp);
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.removeDuplicates("pbbcggttciiippooaais", 2)<<endl;
}