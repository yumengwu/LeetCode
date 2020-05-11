#include "../header.h"

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size(), src = image[sr][sc];
        if (src == newColor) {
            return image;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (q.size()) {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first, j = cur.second;
            image[i][j] = newColor;
            if (i > 0 && image[i - 1][j] == src) {
                q.push(make_pair(i - 1, j));
            }
            if (i < m - 1 && image[i + 1][j] == src) {
                q.push(make_pair(i + 1, j));
            }
            if (j > 0 && image[i][j - 1] == src) {
                q.push(make_pair(i, j - 1));
            }
            if (j < n - 1 && image[i][j + 1] == src) {
                q.push(make_pair(i, j + 1));
            }
        }
        return image;
    }
};

