// 3607. Power Grid Maintenance
// You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).
// These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.
// Initially, all stations are online (operational).
// You are also given a 2D array queries, where each query is one of the following two types:

// [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

// [2, x]: Station x goes offline (i.e., it becomes non-operational).

// Return an array of integers representing the results of each query of type [1, x] in the order they appear.

// Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.
// Example 1:

// Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

// Output: [3,2,3]

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, int gId, vector<int>& groups,
             vector<bool>& seen) {
        seen[u] = true;
        groups[u] = gId;
        for (int v : adj[u]) {
            if (!seen[v]) {
                dfs(v, adj, gId, groups, seen);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> seen(c + 1, false);
        vector<int> groups(c + 1, -1);
        int compCount = 0;
        for (int i = 1; i <= c; ++i) {
            if (!seen[i]) {
                dfs(i, adj, compCount, groups, seen);
                ++compCount;
            }
        }

        vector<set<int>> st(compCount);
        for (int i = 1; i <= c; ++i) {
            st[groups[i]].insert(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> ans;
        

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int g = groups[x];
            if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    st[g].erase(x);
                }
            } else {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    if (st[g].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*st[g].begin());
                    }
                }
            }
        }
        return ans;
    }
};

