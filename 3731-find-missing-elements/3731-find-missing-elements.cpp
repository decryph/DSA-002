class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
            sort(begin(nums), end(nums));
        for(int i =0; i<n-1; i++){
            int x = nums[i];
            int y = nums[i+1];

            for(int j = x+1; j<y; j++){
                ans.push_back(j);
            }
        }
        return ans;
    }
};