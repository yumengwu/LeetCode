#include "../header.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        while (v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while (v1.size() > v2.size()) {
            v2.push_back(0);
        }
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] > v2[i]) {
                return 1;
            }
            if (v1[i] < v2[i]) {
                return -1;
            }
        }
        return 0;
    }
    vector<int> split(string s) {
        vector<int> res;
        if (s.length() == 0) {
            return res;
        }
        string temp = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '.') {
                res.push_back(stoi(temp));
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        if (temp.length()) {
            res.push_back(stoi(temp));
        }
        return res;
    }
};