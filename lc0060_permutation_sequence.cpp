// https://leetcode.com/problems/permutation-sequence/

class Solution {
    int firstNumIndex(int& k, int n) {
        if (n == 1) return 0;
        n--;
 
        int fact = n;
        while (k >= fact && n > 1) {
            fact = fact * (n-1);
            n--;
        }
        int index = k / fact;
        k = k % fact;
 
        return index;
    }
public:
    string getPermutation(int n, int k) {
        set<int> s;
 
        for (int i=1; i <= n; i++)
            s.insert(i);
 
        k = k - 1;
        
        string ans;  
        for (int i=0; i<n; i++) { 
            int index = firstNumIndex(k, n-i);
            
            auto it = s.begin(); 
            advance(it, index);
 
            ans += (*it)+'0'; 
            s.erase(it);
        }
        return ans;
    }
};