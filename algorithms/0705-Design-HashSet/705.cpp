#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        size = 0;
        cap = 16;
        v.resize(cap, list<int>());
    }

    void add(int key) {
        if (size > cap * 0.75) {
            cap *= 2;
            vector<list<int>> nv(cap, list<int>());
            for (int i = 0; i < v.size(); ++i) {
                for (auto it = v[i].begin(); it != v[i].end(); ++it) {
                    nv[getKey(*it)].push_back(*it);
                }
            }
            v = nv;
        }
        v[getKey(key)].push_back(key);
        ++size;
    }

    void remove(int key) {
        v[getKey(key)].remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = getKey(key);
        for (auto it = v[k].begin(); it != v[k].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }

private:
    vector<list<int>> v;
    int size;
    int cap;

    int getKey(int key) {
        return key % cap;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

