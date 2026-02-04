class Solution {
public:
    string removeOuterParentheses(string s) {
        string res ="";
        int lvl =0;
        for(char ch:s){
        if (ch == '('){
            if(lvl>0) res += ch;
            lvl++;
            }
         else if (ch == ')'){
            lvl --;
            if (lvl > 0) res += ch;
         }
    }
    return res;
}
};