#include "../header.h"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int a = A[0], b = B[0], aa = 0, ab = 0, ba = 0, bb = 0;
        for (int i = 0; i < n && (a || b); ++i) {
            if (a) {
                if (A[i] == a && B[i] != a) {
                    ++aa;
                }
                if (B[i] == a && A[i] != a) {
                    ++ab;
                }
                if (A[i] != a && B[i] != a) {
                    a = 0;
                }
            }
            if (b) {
                if (B[i] == b && A[i] != b) {
                    ++ba;
                }
                if (A[i] == b && B[i] != b) {
                    ++bb;
                }
                if (B[i] != b && A[i] != b) {
                    b = 0;
                }
            }
        }
        int res = INT_MAX;
        if (a) {
            res = min(res, min(aa, ab));
        }
        if (b) {
            res = min(res, min(ba, bb));
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    vector<int> a{1,2,1,1,1,2,2,2}, b{2,1,2,2,2,2,2,2};
    Solution s;
    cout<<s.minDominoRotations(a, b)<<endl;
    return 0;
}