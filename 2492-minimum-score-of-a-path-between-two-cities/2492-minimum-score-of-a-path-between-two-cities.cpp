class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        map<int,vector<pair<int,int>>>adj;
        vector<int>vis(n+1,0);
        queue<int>q;

        for(int i=0;i<roads.size();i++){
            int e1 = roads[i][0];
            int e2 = roads[i][1];
            int cst = roads[i][2];

            adj[e1].push_back({e2,cst});
            adj[e2].push_back({e1,cst});
        }

        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto i : adj[ele]){
                ans = min(ans,i.second);
                if(vis[i.first] == 0){
                    q.push(i.first);
                    vis[i.first] = 1;
                }
            }
        }

        return ans;
        
    }
};