// https://leetcode.com/problems/compare-version-numbers/

class Solution {
    int getRevision(int& i,const string& ver) {
        int v=0, ch;
        while (i<ver.size() && (ch = ver[i++]) != '.') {
            v *= 10;
            v += ch-'0';
        }
        return v;
    }
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0, v1=0, v2=0, m=version1.size(), n=version2.size();
        
        while ((v1=getRevision(i,version1)) == (v2=getRevision(j,version2)))
            if (i==m && j==n)
                return 0;
        
        return v1<v2 ? -1 : 1;
    }
};