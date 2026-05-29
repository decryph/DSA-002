class Solution {
public:

    int digSum(int n){
        int sum =0;
        while(n>0){
            sum += n%10;
            n /=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = 37;

        for(int num:nums){
            int s = digSum(num);
            res = min(res,s);
        }
        return res;
    }
};