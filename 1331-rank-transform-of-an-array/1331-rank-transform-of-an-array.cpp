class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp(arr);
        sort(begin(temp), end(temp));

        int rank =1;
        unordered_map<int, int> mpp;
        vector<int> res(n);

        for(int i =0; i< n; i++){
            if(i> 0 && temp[i]> temp[i-1]){
                rank++;
            }
            mpp[temp[i]] = rank;
        }
        for(int j =0; j<n;j++){
            res[j] = mpp[arr[j]];
        }
        return res;
    }
};