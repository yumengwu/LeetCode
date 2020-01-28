#include "../header.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        ++m[x];
    }
    
    void pop() {
        int num = s.top();
        s.pop();
        if (--m[num] == 0) {
            m.erase(num);
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        map<int, int>::iterator it = m.begin();
        return it->first;
    }

private:
    stack<int> s;
    map<int, int> m;
};
