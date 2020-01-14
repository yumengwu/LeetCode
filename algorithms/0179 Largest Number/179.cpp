#include "../header.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        priority_queue<string, vector<string>, Compare> q;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            q.push(to_string(nums[i]));
        }
        while (q.size()) {
            res += q.top();
            q.pop();
        }
        bool allzero = true;
        for (int i = 0; i < res.length(); ++i) {
            if (res[i] != '0') {
                allzero = false;
                break;
            }
        }
        return allzero ? "0" : res;
    }

private:
    struct Compare {
        bool operator()(string s1, string s2) {
            long l1 = stol(s1 + s2);
            long l2 = stol(s2 + s1);
            return l1 < l2;
        }
    };
};

int main()
{
    Solution s;
    vector<int> v{3,30,34,5,9};
    cout<<s.largestNumber(v)<<endl;
    return 0;
}