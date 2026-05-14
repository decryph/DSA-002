class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string d = s+s;
        string sub = d.substr(1,d.size()-2);
        return sub.find(s) != string :: npos;
    }
};