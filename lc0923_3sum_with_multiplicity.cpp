// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long num[100+1] = {}, prime=1e9+7;
        for (auto a : arr) { num[a] += 1; }
        
        long total=0;
        for (int i=0; i<=100; i++) {
            if (num[i] == 0) continue;
            for (int j=i; j<=100; j++) {
                if (num[j] == 0) continue;
                int k = target-i-j;
                if (k < 0 || k > 100 || num[k] == 0) 
                    continue;
                if (i==j && j==k)
                    total += (num[i] * (num[i]-1) * (num[i]-2)) / 6;
                else if (i==j && j!=k)
                    total += (num[i] * (num[i]-1) * num[k]) / 2;
                else if (i < j && j < k)
                    total += num[i] * num[j] * num[k];
            }
        }
        return total % prime;
    }
};