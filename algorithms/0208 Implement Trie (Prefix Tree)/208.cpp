#include "../header.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode * cur = head;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->m[word[i] - 'a'] == NULL) {
                cur->m[word[i] - 'a'] = new trieNode();
            }
            cur = cur->m[word[i] - 'a'];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode * cur = head;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->m[word[i] - 'a'] == NULL) {
                return false;
            }
            cur = cur->m[word[i] - 'a'];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode * cur = head;
        for (int i = 0; i < prefix.length(); ++i) {
            if (cur->m[prefix[i] - 'a'] == NULL) {
                return false;
            }
            cur = cur->m[prefix[i] - 'a'];
        }
        return true;
    }
    
private:
    struct trieNode {
        bool end;
        vector<trieNode *> m;
        trieNode() {
            end = false;
            m.resize(26, NULL);
        }
    };
    trieNode * head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */