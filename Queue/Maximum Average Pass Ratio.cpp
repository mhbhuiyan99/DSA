Problem Link : https://leetcode.com/problems/maximum-average-pass-ratio/description/
Explanation : https://youtu.be/vZwgYBpe92A?si=zouasXeVU2Q0mRYB

double maxAverageRatio(vector<vector<int>>& classes, int eS) {
        
        priority_queue< pair<double, pair<int,int> > > pq;

        int n = classes.size();

        for(int i = 0; i<n; i++)
        {
            int pass = classes[i][0];
            int total = classes[i][1];
            
            double dif = (double)(pass + 1)/(total + 1) - (double)pass/total;

            pq.push({dif, {pass, total}});
        }

        while(eS--)
        {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pass++;
            total++;

            double newDif = (double)(pass + 1)/(total + 1) - (double)pass/total;

            pq.pop();
            pq.push({newDif, {pass, total}});
        }

        double ratio = 0;
        while(!pq.empty()) 
        {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;

            ratio += (double)(pass)/(total);

            pq.pop();
        }

        return ratio / n;
    }
