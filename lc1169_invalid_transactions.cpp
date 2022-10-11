// https://leetcode.com/problems/invalid-transactions/

class Solution {
    struct Trans {
        string name,city,trans;
        int time,value;
        bool bad;
        Trans(const string& s) {
            istringstream ss(s);
            getline(ss,name,','); 
            getline(ss,trans,','); time=stoi(trans);
            getline(ss,trans,','); value=stoi(trans);
            getline(ss,city); 
            bad = false;
            trans = s;
        }
        bool operator<(const Trans& rhs) { return name<rhs.name || (name==rhs.name && time<rhs.time); }
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Trans> tr;
        for (auto trans : transactions) { tr.emplace_back(trans); }
        
        sort(tr.begin(),tr.end());        
        vector<string> result;
        
        for (int i=0; i<tr.size(); i++) {
            if (tr[i].value > 1000 && tr[i].bad == false) 
                result.push_back(tr[i].trans), tr[i].bad = true;
            for (int j=i+1; j<tr.size() && tr[i].name == tr[j].name; j++) {
                if (tr[i].city != tr[j].city && (tr[j].time - tr[i].time <= 60)) {
                    if (tr[i].bad == false) result.push_back(tr[i].trans), tr[i].bad = true;
                    if (tr[j].bad == false) result.push_back(tr[j].trans), tr[j].bad = true;
                }
            }
        }
        return result;
    }
};