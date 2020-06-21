#include "../header.h"

// 1000000 space
class MyHashMap {
public:
    MyHashMap() {
        v.resize(1000001, -1);
    }

    void put(int key, int value) {
        v[key] = value;
    }

    int get(int key) {
        return v[key];
    }

    void remove(int key) {
        v[key] = -1;
    }

private:
    vector<int> v;
};

