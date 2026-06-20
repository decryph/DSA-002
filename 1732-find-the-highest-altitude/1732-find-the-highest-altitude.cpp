class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int maxA = 0;
       int curr =0;

       for(int &g : gain){
        curr+= g;
        maxA = max(maxA, curr);
       } 
       return maxA;
    }
};