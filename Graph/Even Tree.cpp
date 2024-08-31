Problem Link: www.hackerrank.com/challenges/even-tree/problem?isFullScreen=true#!

>>>  DFS  <<<  [ youtu.be/T56efbMposY?si=xRbvLzGntnSeSmwM ]

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl '\n'
#define ll long long

vector<ll> v[101];
ll vis[101];
ll cnt = 0;

ll dfs(ll node)
{
    vis[node] = 1;
    ll total_nodes = 0;
    for(auto u : v[node])
    {
        if(!vis[u])
        {
            ll nodes_cnt = dfs(u);
            if(nodes_cnt % 2 == 0)
                cnt++;
            else total_nodes += nodes_cnt;
        }
    }
    return total_nodes + 1;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    
    while(m--)
    {
        ll x,y; cin >> x >> y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    
    dfs(1);
    cout << cnt << nl;
}
