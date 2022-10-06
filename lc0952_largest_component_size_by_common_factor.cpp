// https://leetcode.com/problems/largest-component-size-by-common-factor/

class UF {
    vector<int> parent, size;
public:
    int maxsize=1;
    UF(int n) : parent(n), size(n,1) { iota(parent.begin(),parent.end(),0); }
    
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unify(int x,int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) 
                swap(x,y);
            parent[y] = x;
            size[x] += size[y];
            maxsize = max(maxsize,size[x]);
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        UF uf(nums.size());
        unordered_map<int,int> mp;
        
        for (int i=0; i<nums.size(); i++) {
            auto num = nums[i];
            for (int f=2; f*f<=num; f++) {
                if (num%f == 0) {
                    if (mp.count(f))
                        uf.unify(i,mp[f]);
                    else
                        mp[f] = i;
                    if (mp.count(num/f))
                        uf.unify(i,mp[num/f]);
                    else
                        mp[num/f] = i;
                }
            }
            if (mp.count(num))
                uf.unify(i,mp[num]);
            else
                mp[num] = i;
        }
        return uf.maxsize;
    }
};