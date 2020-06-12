#include "../header.h"

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.length(), cntc = 0, cntr = 0, cnto = 0, cnta = 0, cntk = 0;
        for (int i = 0; i < n; ++i) {
            switch (croakOfFrogs[i]) {
                case 'c':
                    ++cntc;
                    break;
                case 'r':
                    ++cntr;
                    break;
                case 'o':
                    ++cnto;
                    break;
                case 'a':
                    ++cnta;
                    break;
                case 'k':
                    ++cntk;
                    break;
                default:
                    return -1;
            }
        }
        if (!(cntc == cntr && cntc == cnto && cntc == cnta && cntc == cntk)) {
            return -1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int curmax;
            switch (croakOfFrogs[i]) {
                case 'c':
                    --cntc;
                    if (cntr <= cntc || cnto <= cntc || cnta <= cntc || cntk <= cntc) {
                        return -1;
                    }
                    curmax = cntr - cntc;
                    curmax = max(curmax, cnto - cntc);
                    curmax = max(curmax, cnta - cntc);
                    curmax = max(curmax, cntk - cntc);
                    res = max(res, curmax);
                    break;
                case 'r':
                    --cntr;
                    if (cnto <= cntr || cnta <= cntr || cntk <= cntr) {
                        return -1;
                    }
                    if (cntc > cntr) {
                        return -1;
                    }
                    curmax = cnto - cntr;
                    curmax = max(curmax, cnta - cntr);
                    curmax = max(curmax, cntk - cntr);
                    res = max(res, curmax);
                    break;
                case 'o':
                    --cnto;
                    if (cnta <= cnto || cntk <= cnto) {
                        return -1;
                    }
                    if (cntc > cnto || cntr > cnto) {
                        return -1;
                    }
                    curmax = cnta - cnto;
                    curmax = max(curmax, cntk - cntr);
                    res = max(res, curmax);
                    break;
                case 'a':
                    --cnta;
                    if (cntk <= cnta) {
                        return -1;
                    }
                    if (cntc > cnta || cntr > cnta || cnto > cnta) {
                        return -1;
                    }
                    curmax = cntk - cnta;
                    res = max(res, curmax);
                    break;
                case 'k':
                    --cntk;
                    if (cntc > cntk || cntr > cntk || cnto > cntk || cnta > cntk) {
                        return -1;
                    }
                    break;
            }
        }
        if (cntc || cntr || cnto || cnta || cntk) {
            return -1;
        }
        return res;
    }
};

