#include "../header.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string str = "";
        for (int i = 0; i < strs.size(); ++i) {
            str += to_string(strs[i].length());
            str += " ";
            str += strs[i];
        }
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> v;
        int idx = 0;
        while (idx < s.length()) {
            int next = idx + 1;
            while (s[next] != ' ') ++next;
            int len = stoi(s.substr(idx, next - idx));
            idx = next + 1;
            v.push_back(s.substr(idx, len));
            idx += len;
        }
        return v;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));