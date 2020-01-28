#include "../header.h"

class Solution {
public:
    struct point {
        int index;
        float dist;
    };
    
    vector<vector<point>> partition(vector<point> & v) {
        vector<vector<point>> res;
        res.resize(2);
        res[0].resize(0);
        res[1].resize(0);
        float flag = v[0].dist;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].dist <= flag) {
                res[0].push_back(v[i]);
            }
            else {
                res[1].push_back(v[i]);
            }
        }
        if (res[0].size() >= res[1].size()) {
            res[1].push_back(v[0]);
        }
        else {
            res[0].push_back(v[0]);
        }
        return res;
    }

    vector<point> selectTopK(vector<point> v, int k) {
        vector<point> res;
        if (k <= 0) {
            return res;
        }
        else if (v.size() <= k) {
            return v;
        }
        vector<vector<point>> s2 = partition(v);
        res = selectTopK(s2[0], k);
        vector<point> temp = selectTopK(s2[1], k - s2[0].size());
        res.insert(res.end(), temp.begin(), temp.end());
        return res;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        int n = points.size();
        vector<point> v(n);
        for (int i = 0; i < n; ++i) {
            point p;
            p.index = i;
            p.dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            v[i] = p;
        }
        if (K == 1) {
            int index = 0;
            float mindist = v[0].dist;
            for (int i = 1; i < n; ++i) {
                if (v[i].dist < mindist) {
                    index = i;
                    mindist = v[i].dist;
                }
            }
            res.push_back(points[index]);
            return res;
        }
        v = selectTopK(v, K);
        for (int i = 0; i < K; ++i) {
            res.push_back(points[v[i].index]);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> v{{-95,76},{17,7},{-55,-58},{53,20},{-69,-8},{-57,87},{-2,-42},{-10,-87},{-36,-57},{97,-39},{97,49}};
    Solution s;
    v = s.kClosest(v, 5);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i][0]<<' '<<v[i][1]<<endl;
    }
    return 0;
}