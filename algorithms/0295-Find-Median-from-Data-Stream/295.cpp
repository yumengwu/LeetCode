#include "../header.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(-maxheap.top());
        maxheap.pop();
        if (maxheap.size() < minheap.size()) {
            maxheap.push(-minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (maxheap.size() == 0) {
            return 0;
        }
        if (maxheap.size() == minheap.size()) {
            return (maxheap.top() - minheap.top()) * 0.5;
        }
        else {
            return maxheap.top();
        }
    }
private:
    priority_queue<int> maxheap, minheap;
};

int main()
{
    return 0;
}