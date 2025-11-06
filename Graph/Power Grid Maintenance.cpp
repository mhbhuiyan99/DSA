// Problem Link: https://leetcode.com/problems/power-grid-maintenance/description/

class Solution {
public:
    int par[100005];

    int find(int a) {
        if (par[a] == a) return a;
        return par[a] = find(par[a]);
    }

    void Union(int a, int b) {
        par[a] = b;
    }

    vector<int> processQueries(int c, vector<vector<int>>&con, vector<vector<int>>&qu) {
        for(int i=1; i<=c; i++)
            par[i] = i;

        int n = con.size();
        for(int i=0; i<n; i++) {
            int x = find(con[i][0]);
            int y = find(con[i][1]);

            if(x != y) 
                Union(x, y);
        }

        unordered_map<int, set<int>> mp;
        for(int i=1; i<=c; i++) {
            find(i);
            mp[par[i]].insert(i);
        }

        vector<int> ans;
        for(auto q : qu) {
            int x = q[0];
            int y = q[1];

            if(x == 1) {
                if(mp[par[y]].count(y)) 
                    ans.push_back(y);
                else if(mp[par[y]].size() == 0) 
                    ans.push_back(-1);
                else {
                    auto it = mp[par[y]].begin();
                    ans.push_back(*it);
                }
            } else {
                mp[par[y]].erase(y);
            }
        }
        return ans;
    }
};
