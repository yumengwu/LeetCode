#include "../header.h"

class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.length() == 0) {
            return false;
        }
        return std::regex_match(s, std::regex("[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?"));
    }
    
    string trim(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < n && s[l] == ' ') ++l;
        while (r >= 0 && s[r] == ' ') --r;
        return r - l >= 0 ? s.substr(l, r - l + 1) : "";
    }
};

int main()
{
    Solution s;
    cout<<s.isNumber("4 9")<<endl;
    return 0;
}

