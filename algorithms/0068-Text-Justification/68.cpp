#include "../header.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        vector<int> cntc;
        vector<vector<string>> record;
        int cnt = 0;
        int index = 0;
        while (index < n) {
            vector<string> temp;
            cnt = 0;
            temp.push_back(words[index]);
            cnt += words[index].length();
            index++;
            if (cnt < maxWidth) {
                while (index < n && cnt + words[index].length() + 1 <= maxWidth) {
                    cnt += words[index].length() + 1;
                    temp.push_back(words[index]);
                    index++;
                }
            }
            record.push_back(temp);
            cntc.push_back(cnt);
        }
        for (int i = 0; i < record.size(); ++i) {
            if (i == record.size() - 1) {
                string str = record[i][0];
                for (int j = 1; j < record[i].size(); ++j) {
                    str += " " + record[i][j];
                }
                while (str.length() < maxWidth) {
                    str += " ";
                }
                res.push_back(str);
            }
            else {
                int extraWhiteSpace = maxWidth - cntc[i];
                string str = record[i][0];
                if (record[i].size() == 1) {
                    while (str.length() < maxWidth) {
                        str += " ";
                    }
                }
                else {
                    int numSpace = record[i].size() - 1;
                    vector<int> cntspace(numSpace, 1);
                    int index = record[i].size() - 1;
                    while (index > 0) {
                        cntspace[index - 1] += extraWhiteSpace / numSpace;
                        index--;
                        extraWhiteSpace -= extraWhiteSpace / numSpace;
                        numSpace--;
                    }
                    for (int j = 0; j < cntspace.size(); ++j) {
                        for (int k = 0; k < cntspace[j]; ++k) {
                            str += " ";
                        }
                        str += record[i][j + 1];
                    }
                }
                res.push_back(str);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> v{"This", "is", "an", "example", "of", "text", "justification."};
    Solution s;
    v = s.fullJustify(v, 16);
    for (int i = 0; i < v.size(); ++i) {
        cout<<"\""<<v[i]<<"\""<<endl;
    }
    return 0;
}