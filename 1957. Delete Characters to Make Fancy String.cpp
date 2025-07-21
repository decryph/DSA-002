
// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.

class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<= 2){
            return s;
        }
        string res ="";

        for(int i=0; i<s.length(); i++){
            char curr = s[i];
            if (res.length() >= 2 && res[res.length()-1] == curr && res[res.length()-2]== curr){
                continue;
            }
            res += curr;
        }

        return res;
    }
};
