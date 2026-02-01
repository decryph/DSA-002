class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int firstmin = nums[0];
        int secondmin = INT_MAX;
        int thirdmin = INT_MAX;

        for(int i =1; i< n; i++){
            if(nums[i] < secondmin){
                thirdmin = secondmin;
                secondmin = nums[i];
            }else if(nums[i] < thirdmin){
                thirdmin = nums[i];
            }
        }
        return firstmin + secondmin + thirdmin;
    }
};