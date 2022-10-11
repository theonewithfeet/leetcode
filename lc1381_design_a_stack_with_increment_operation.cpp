// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
    vector<int> stk; 
    int idx, max;  
public:
    CustomStack(int maxSize) : stk(maxSize), idx(0), max(maxSize) {}
    
    void push(int x) {
        if (idx < max) stk[idx++] = x;   
    }
    
    int pop() {
        return (idx > 0) ? stk[--idx] : -1;
    }
    
    void increment(int k, int val) {
        k = min(k,idx);
        for (int i=0; i<k; i++) stk[i] += val;
    }
};
