class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total_sq =0;

        for(int i =0; i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j]==1){
                    if(i>0 && j>0){
                        int top= matrix[i-1][j];
                        int left = matrix[i][j-1];
                        int diag = matrix[i-1][j-1];

                        matrix[i][j] = min({top,left,diag})+1;
                    }
                    total_sq += matrix[i][j];
                }
            }
        }
        return total_sq;
    }
};