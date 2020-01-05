#include "../header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> v{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        vector<unsigned long long> t;
        t.resize(strs.size());
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); ++i) {
            t[i] = 1;
            for (int j = 0; j < strs[i].length(); ++j) {
                t[i] *= v[strs[i][j] - 'a'];
            }
        }
        map<unsigned long long, vector<string>> m;
        for (int i = 0; i < t.size(); ++i) {
            if (m.find(t[i]) != m.end()) {
                vector<string> tempvec = m[t[i]];
                tempvec.push_back(strs[i]);
                m[t[i]] = tempvec;
            }
            else {
                vector<string> tempvec{strs[i]};
                m[t[i]] = tempvec;
            }
        }
        for (map<unsigned long long, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         unordered_map<string, vector<string>> m;
//         for (int i = 0; i < strs.size(); ++i) {
//             vector<int> v(26, 0);
//             for (int j = 0; j < strs[i].length(); ++j) {
//                 ++v[strs[i][j] - 'a'];
//             }
//             string key = "";
//             for (int j = 0; j < 26; ++j) {
//                 // key += "-";
//                 key += v[j];
//             }
//             m[key].push_back(strs[i]);
//         }
//         for (auto it = m.begin(); it != m.end(); ++it) {
//             res.push_back(it->second);
//         }
//         return res;
//     }
// };