#include "../header.h"

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie * cur = head;
        int idx = 0, n = word.length();
        for (int i = 0; i < n; ++i) {
            if (cur->next[word[i] - 'a'] == NULL) {
                cur->next[word[i] - 'a'] = new trie();
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(head, word, 0);
    }

private:
    struct trie {
        vector<trie *> next;
        bool end;
        trie() {
            end = false;
            next.resize(26, NULL);
        }
    };
    
    trie * head;
    
    bool helper(trie * node, string & str, int idx) {
        if (node == NULL) {
            return false;
        }
        if (idx == str.length()) {
            return node->end;
        }
        if (str[idx] != '.') {
            return helper(node->next[str[idx] - 'a'], str, idx + 1);
        }
        else {
            for (int i = 0; i < 26; ++i) {
                if (node->next[i] && helper(node->next[i], str, idx + 1)) {
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    WordDictionary w;
    w.addWord("at");
    w.addWord("and");
    w.addWord("an");
    w.addWord("add");
    cout<<w.search("a")<<endl;
    cout<<w.search(".at")<<endl;
    w.addWord("bat");
    cout<<w.search(".at")<<endl;
    cout<<w.search("an.")<<endl;
    cout<<w.search("a.d.")<<endl;
    cout<<w.search("b.")<<endl;
    cout<<w.search("a.d")<<endl;
    cout<<w.search(".")<<endl;
    return 0;
}