// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=1,hi=arr.size()-2;
        
        while (lo<=hi) {
            int mid = lo+(hi-lo)/2;
            
            if (arr[mid-1] < arr[mid]) {
                if (arr[mid] > arr[mid+1]) return mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return -1;
    }
};