class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int cntless =0, cntequal =0;

        for(int &num: nums){
            if(num< pivot){
                cntless++;
            } else if(num == pivot){
                cntequal++;
            }
        }
        int i=0, j = cntless,  k = cntless+ cntequal;
        vector<int> ans(n);
        for(int &num : nums){
            if(num < pivot){
                ans[i] = num;
                i++;
            } else if(num == pivot){
                ans[j] = num;
                j++;
            } else{
                ans[k] = num;
                k++;
            }
        }
        return ans;
    }
};