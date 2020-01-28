#include "../header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n = num1.size(), m = num2.size();
        vector<short> v(n + m, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int c = 0;
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
                c = v[i + j] / 10;
                v[i + j] %= 10;
                int k = i + j + 1;
                while (c) {
                    v[k] += c;
                    c = v[k] / 10;
                    v[k] %= 10;
                    k++;
                }
            }
        }
        reverse(v.begin(), v.end());
        int index = 0;
        while (index < v.size() && v[index] == 0) {
            index++;
        }
        if (index == v.size()) {
            return "";
        }
        string res = "";
        while (index < v.size()) {
            res += v[index++] + '0';
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.multiply("1231231231231232138213", "3453458345345739843")<<endl;
    return 0;
}