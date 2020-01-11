#include "../header.h"

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int wn = words.size();
        if (wn == 0) {
            return res;
        }
        int m = board.size();
        if (m == 0) {
            return res;
        }
        int n = board[0].size();
        if (n == 0) {
            return res;
        }
        trie * head = new trie();
        for (int i = 0; i < wn; ++i) {
            addWord(head, words[i]);
        }
        set<string> ss;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (head->m[board[i][j] - 'a']) {
                    search(board, i, j, head->m[board[i][j] - 'a'], ss);
                }
            }
        }
        for (auto it = ss.begin(); it != ss.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
    
private:
    struct trie {
        bool end;
        vector<trie *> m;
        string str;
        trie() {
            end = false;
            str = "";
            m.resize(26, NULL);
        }
    };
    
    void addWord(trie * head, string word) {
        for (int i = 0; i < word.length(); ++i) {
            if (head->m[word[i] - 'a'] == NULL) {
                head->m[word[i] - 'a'] = new trie();
            }
            head = head->m[word[i] - 'a'];
        }
        head->end = true;
        head->str = word;
    }
    
    void search(vector<vector<char>>& b, int row, int col, trie * node, set<string> & res) {
        int m = b.size(), n = b[0].size();
        if (node->end) {
            res.insert(node->str);
        }
        char temp = b[row][col];
        b[row][col] = '.';
        if (row > 0 && b[row - 1][col] >= 'a' && b[row - 1][col] <= 'z' && node->m[b[row - 1][col] - 'a']) {
            search(b, row - 1, col, node->m[b[row - 1][col] - 'a'], res);
        }
        if (row < m - 1 && b[row + 1][col] >= 'a' && b[row + 1][col] <= 'z' && node->m[b[row + 1][col] - 'a']) {
            search(b, row + 1, col, node->m[b[row + 1][col] - 'a'], res);
        }
        if (col > 0 && b[row][col - 1] >= 'a' && b[row][col - 1] <= 'z' && node->m[b[row][col - 1] - 'a']) {
            search(b, row, col - 1, node->m[b[row][col - 1] - 'a'], res);
        }
        if (col < n - 1 && b[row][col + 1] >= 'a' && b[row][col + 1] <= 'z' && node->m[b[row][col + 1] - 'a']) {
            search(b, row, col + 1, node->m[b[row][col + 1] - 'a'], res);
        }
        b[row][col] = temp;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v1{{'a'}};
    vector<string> v2 = {"a"};
    vector<string> vv = s.findWords(v1, v2);
    for (int i = 0; i < vv.size(); ++i) {
        cout<<vv[i]<<endl;
    }
    return 0;
}