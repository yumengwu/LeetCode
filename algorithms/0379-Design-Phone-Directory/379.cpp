#include "../header.h"

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            q.push(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (q.size() == 0) {
            return -1;
        }
        int res = q.front();
        q.pop();
        used.insert(res);
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return used.count(number) == 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used.count(number)) {
            used.erase(number);
            q.push(number);
        }
    }
    
private:
    unordered_set<int> used;
    queue<int> q;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

int main()
{
    return 0;
}