class Solution {
public:

int dp[201][201];
bool vis[201][201];

int solve(vector<vector<int>>& triangle, int row, int col){
    int n = triangle.size();
    if(row == n-1)
    return triangle[row][col];

   if(vis[row][col])
        return dp[row][col];
    
    vis[row][col]= true;

    int down = solve(triangle, row+1,col);
    int diagonal = solve(triangle, row+1, col+1);

    return dp[row][col] = triangle[row][col] + min(down,diagonal);
}
    int minimumTotal(vector<vector<int>>& triangle) {
       
       memset(vis,false,sizeof(vis));
       return solve(triangle,0,0);
    }
};