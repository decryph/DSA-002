class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> N;

        for (int i = 0; i < numRows; i++) {
            vector<int> ansRow;
            long long ans = 1;
            ansRow.push_back(1); 

            for (int col = 1; col <= i; col++) {
                ans = ans * (i - col + 1) / col;
                ansRow.push_back(ans);
            }

            N.push_back(ansRow);
        }

        return N;
    }
};