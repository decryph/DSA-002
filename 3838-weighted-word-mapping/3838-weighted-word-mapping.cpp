class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for( const string& w : words){
            long long totW = 0;
            for(char ch : w){
                int idx = ch - 'a';
                totW += weights[idx];
            }
            int modV = totW % 26;
            char mapp = 'z' - modV;
            res.push_back(mapp);
        }
        return res;
    }
};