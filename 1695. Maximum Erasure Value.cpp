// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int L= 0;
        int R =0;
        int n = nums.size();
        unordered_map<int,bool> val_idx;

        int max_sum = INT_MIN;
        int win_sum =0;

        while(R<n){
            if(val_idx.count(nums[R])){
                (val_idx.erase(nums[L]));
                win_sum -= nums[L];
                L++;
            } else{
                win_sum += nums[R];
                val_idx[nums[R]] = true;
                R++;
                max_sum = max(win_sum,max_sum);
            }
        }
        return max_sum;
    }
};
