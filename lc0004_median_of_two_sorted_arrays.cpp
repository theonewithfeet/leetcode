// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
    int findKth(vector<int>& A, vector<int>& B, int k) {
        int m = A.size(), n = B.size();

        if (m > n) return findKth(B, A, k);

        int lo = 0, hi = m;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int idx = k - 1 - mid;
            
            if (0 <= idx && idx < n && A[mid] >= B[idx]) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        int i = lo - 1;
        int j = k - 1 - lo;
        
        return max(i < 0 ? INT_MIN : A[i], j < 0 ? INT_MIN : B[j]);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m + n) / 2;
        
        if ((m + n) % 2 == 1) 
            return findKth(nums1, nums2, k + 1);
        
        return (findKth(nums1, nums2, k) + findKth(nums1, nums2, k + 1)) / 2.0;
    }

};