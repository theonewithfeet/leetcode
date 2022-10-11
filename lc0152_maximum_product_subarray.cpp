// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=INT_MIN;
        for (int i=0, prod=1; i<nums.size(); i++) {
            maxprod = max(maxprod,prod *= nums[i]);
            prod = prod ? prod : 1;
        }
        for (int i=nums.size()-1, prod=1; i>=0; i--) {
            maxprod = max(maxprod,prod *= nums[i]);
            prod = prod ? prod : 1;
        }
        return maxprod;
    }
};