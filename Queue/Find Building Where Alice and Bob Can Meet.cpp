Problem Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/
Tutorial : https://youtu.be/5CTpIGzrbDg?si=UVazhr_257_7J2DN
-
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int totalQueries = queries.size();

        vector<int> ans(totalQueries, -1);
        unordered_map<int, vector<pair<int,int>>> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int q=0; q<totalQueries; q++) {
            int i = queries[q][0];
            int j = queries[q][1];
            if (i < j && heights[i] < heights[j])
                ans[q] = j;
            else if (i > j && heights[i] > heights[j])
                ans[q] = i;
            else if (i == j)
                ans[q] = i;
            else
                mp[max(i, j)].push_back({max(heights[i], heights[j]), q});
        }
        for (int i=0; i<n; i++) {
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for (auto &it : mp[i])
                pq.push(it);
        }
        return ans;
    }
};
