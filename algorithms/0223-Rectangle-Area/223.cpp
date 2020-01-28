#include "../header.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (D - B) * (C - A) - (E >= C || F >= D || B >= H || A >= G ? 0 : ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))))+ (H - F) * (G - E);
    }
};