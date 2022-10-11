// https://leetcode.com/problems/rank-teams-by-votes/

class Solution {
    struct Team {
        int votes[26] = {0};
        char letter;
        Team(char ch) : letter(ch) {}
    };
    static bool compare(const Team& a,const Team& b) {
        for (int i=0; i<26; i++) {
            if (a.votes[i] == b.votes[i]) continue;
            return a.votes[i] > b.votes[i];
        }
        return a.letter < b.letter;
    }
public:
    string rankTeams(vector<string>& votes) {
        vector<Team> teams;
        for (char ch='A'; ch<='Z'; ch++)
            teams.emplace_back(ch);
        
        for (auto vote: votes) 
            for (int i=0; i<vote.size(); i++)
                teams[vote[i]-'A'].votes[i] += 1;

        sort(teams.begin(),teams.end(),compare);
        
        string result;
        for (int i=0; i<votes[0].size(); i++)
            result += teams[i].letter;
        
        return result;
    }
};