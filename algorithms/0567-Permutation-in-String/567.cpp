#include "../header.h"

class Solution {
public:
    bool isZero(vector<int> & v) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != 0) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) {
            return false;
        }
        vector<int> cnt(26, 0);
        for (int i = 0; i < len1; ++i) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }
        if (isZero(cnt)) {
            return true;
        }
        for (int i = 1; i <= len2 - len1; ++i) {
            cnt[s2[i - 1] - 'a']--;
            cnt[s2[i + len1 - 1] - 'a']++;
            if (isZero(cnt)) {
                return true;
            }
        }
        return isZero(cnt);
    }
};

int main()
{
    Solution s;
    cout<<s.checkInclusion("ab", "eidbaooo")<<endl;
    return 0;
}