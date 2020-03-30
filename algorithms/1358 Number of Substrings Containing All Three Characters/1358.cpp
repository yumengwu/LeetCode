#include "../header.h"

static int faster=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 13;}();

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> cnt(3, 0);
        int left = 0, right = 0, n = s.length();
        while (right < n) {
            while (right < n) {
                ++cnt[s[right++] - 'a'];
                if (hasAll(cnt)) {
                    break;
                }
            }
            if (!hasAll(cnt)) {
                break;
            }
            res += n - right + 1;
            while (left < n) {
                --cnt[s[left++] - 'a'];
                if (!hasAll(cnt)) {
                    break;
                }
                res += n - right + 1;
            }
        }
        return res;
    }
    
    bool hasAll(vector<int>& cnt) {
        return cnt[0] && cnt[1] && cnt[2];
    }
};

int main()
{
    Solution s;
    cout<<s.numberOfSubstrings("abab")<<endl;
    return 0;
}