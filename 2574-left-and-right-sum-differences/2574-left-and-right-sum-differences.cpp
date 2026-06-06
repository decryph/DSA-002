class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int curr = 0;

        vector<int> ans(n);
        for(int i =0; i<n;i++){
            int leftsum= curr;
            curr += nums[i];
            int rightsum = sum - curr;

            ans[i] = abs(rightsum-leftsum);
        }
        return ans;
    }
};