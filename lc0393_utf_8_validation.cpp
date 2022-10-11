// https://leetcode.com/problems/utf-8-validation/

class Solution {   
public:
    bool validUtf8(vector<int>& data) {
        int count=0;
        for (auto x : data) {
            if (count) {
                if ((x >> 6) != 0b010) return false;
                count -= 1;
            }
            else {
                if ((x & 0b10000000) == 0) continue;
                else if ((x >> 5) == 0b0110)   count = 1;
                else if ((x >> 4) == 0b01110)  count = 2;
                else if ((x >> 3) == 0b011110) count = 3;
                else return false;
            }
        }
        return count == 0;
    }
};