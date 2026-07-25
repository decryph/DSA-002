class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();  
        bitset<2048> pair;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                pair.set(nums[i] ^ nums[j]);
            }
        }   
        bitset<2048> triplets;  
        for(int i = 0; i<2048; i++){
            if(pair[i]){
                for(int val : nums){
                    triplets.set(i ^ val);
                }
            }
        }
        return triplets.count();
    }
};