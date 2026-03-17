#include <limits>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int currMax= nums[0];
        int currMin = nums[0];
        int globalMax = nums[0];

        for(size_t i = 1; i<nums.size();i++){
            int n = nums[i];

            if(n<0){
                std::swap(currMax, currMin);
            }
            currMax = std::max(n,currMax*n);
            currMin = std::min(n,currMin*n);

            globalMax = std::max(globalMax,currMax);
        }
        return globalMax;
    }
};