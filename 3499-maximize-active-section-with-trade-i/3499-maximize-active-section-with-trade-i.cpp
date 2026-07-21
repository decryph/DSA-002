class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int active = count(s.begin(), s.end(), '1');

        vector<int> inactive;
        int i =0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i] == '0') i++;

                inactive.push_back(i-start);
            } else{
                i++;
            }
        }
        int maxp =0;
        for(int i =1; i<inactive.size();i++){
            maxp = max(maxp, inactive[i]+ inactive[i-1]);
        }
        return maxp +active;
    }
};