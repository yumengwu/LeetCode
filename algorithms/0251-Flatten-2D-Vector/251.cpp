#include "../header.h"

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        if (v.size()) {
            arr = v[0];
            for (int i = 1; i < v.size(); ++i) {
                arr.insert(arr.end(), v[i].begin(), v[i].end());
            }
        }
        it = arr.begin();
    }
    
    int next() {
        int res = *it;
        ++it;
        return res;
    }
    
    bool hasNext() {
        return it != arr.end();
    }
    
private:
    vector<int> arr;
    vector<int>::iterator it;
};