#include "../header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "" && num2 == "") {
            return "";
        }
        if (num1 == "") {
            return num2;
        }
        if (num2 == "") {
            return num1;
        }
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0, idx = max(i1, i2) + 1;
        string res(max(i1 + 1, i2 + 1) + 1, '0');
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            int a = i1 >= 0 ? num1[i1] - '0' : 0;
            int b = i2 >= 0 ? num2[i2] - '0' : 0;
            int temp = a + b + carry;
            carry = temp / 10;
            temp %= 10;
            res[idx--] = char(temp + '0');
            --i1;
            --i2;
        }
        return res[0] == '0' ? res.substr(1, res.length() - 1) : res;
    }
};

/*
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i1 = 0, i2 = 0, c = 0;
        while (i1 < num1.length() || i2 < num2.length() || c) {
            int n1 = i1 < num1.length() ? num1[i1] - '0' : 0;
            int n2 = i2 < num2.length() ? num2[i2] - '0' : 0;
            int t = n1 + n2 + c;
            res += t % 10 + '0';
            c = t / 10;
            ++i1;
            ++i2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};*/

int main()
{
    Solution s;
    cout<<s.addStrings("0", "0")<<endl;
    return 0;
}
