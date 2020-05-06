#include "../header.h"

class Solution {
public:
    string intToRoman(int num) {
        string one[] = {"", "M", "MM", "MMM"};
        string two[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string three[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string four[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return one[num / 1000] + two[(num % 1000) / 100] + three[(num % 100) / 10] + four[num % 10];
    }
};