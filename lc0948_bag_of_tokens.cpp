// https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int score=0, point=0, i=0, j=tokens.size()-1;
        
        while (i<=j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                score  = max(score,++point);
            }
            else if (point > 0) {
                power += tokens[j--];
                point -= 1;
            }
            else
                break;
        }
        return score;
    }
};