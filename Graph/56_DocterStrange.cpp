#include <bits/stdc++.h>
using namespace std;

// have a look

class Solution{
    int *low,*dis,children,time;
    vector<int> *adj;
    public:
    void AP(int src,int par,int &cnt){
        dis[src]=low[src]=++time;
        int x=0;
        for(auto it: adj[src]){
            if(it==par)
                continue;
            if(!dis[it]){
                AP(it,src,cnt);
                low[src] = min(low[src],low[it]);
                if(par==-1)
                    children++;
                else if(low[it]>=dis[src])
                    x++;
            }else
                low[src] = min(low[src],dis[it]);
        }
        cnt+=x>0?1:0;
    }
    int doctorStrange(int N, int M, vector<vector<int>> & graph)
    {
        low=new int[N+1],dis=new int[N+1],children=0,time=0,adj= new vector<int>[N+1];
        
        for(int i=1;i<=N;i++)
            low[i]=dis[i]=0;
            
        for(int i=0;i<M;i++)
            adj[graph[i][0]].push_back(graph[i][1]), adj[graph[i][1]].push_back(graph[i][0]);
        
        int cnt=0;
        AP(1,-1,cnt);
        if(children>1)
            cnt++;
        return cnt;
    }
    ~Solution(){
        delete [] low,dis,adj;
    }
};