Problem Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:

    bool isPossible(int node, int color[], bool graph[101][101], int n, int col)
    {
        for(int k = 0; k < n; k++)
        {
            if(k != node and graph[k][node] == 1 and color[k] == col)
                return false;
        }
        return true;
    }
    
    bool solve(int node, int color[], bool graph[101][101], int m, int n)
    {
        if(node == n)
            return true;
        for(int i=1; i<=m; i++)
        {
            if(isPossible(node, color, graph, n, i))
                {
                    color[node] = i;
                    if(solve(node+1, color, graph, m, n))
                        return true;
                    color[node] = 0;
                }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        int color[n] = {0};
        if(solve(0, color, graph, m , n))
            return true;
        return false;
    }
};
