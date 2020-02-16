#include "../header.h"

class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> m;
};
