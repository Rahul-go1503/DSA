#include <bits/stdc++.h>
using namespace std;

#define vd vector<double>
#define pdi pair<double,int>
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        unordered_map<string,int> mp;
        int index =0;
        for(auto &e : eq){
            if(!mp.count(e[0])) mp[e[0]] = index++;
            if(!mp.count(e[1])) mp[e[1]] = index++;
        }
        int V = mp.size();
        vector<pair<int,double>> adj[V];

        int E = eq.size();
        for(int i=0;i<E;i++){
            adj[mp[eq[i][0]]].push_back({mp[eq[i][1]],val[i]});
            adj[mp[eq[i][1]]].push_back({mp[eq[i][0]],1/val[i]});
        }

        vector<vd> dis(V,vd(V,DBL_MAX));
        for(int i=0;i<V;i++) dis[i][i] = 1.0;

        for(int i=0;i<V;i++){
            // no need to use pq bcoz u/v ki value agar hai to unique hogi
            priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
            pq.push({1.0,i});

            while(pq.size()){
                int u = pq.top().second;
                double d = pq.top().first;
                pq.pop();

                if(d>dis[i][u]) continue;
                for(auto &p : adj[u]){
                    int v = p.first;
                    double wt = p.second;

                    if(d*wt < dis[i][v]){
                        dis[i][v] = d*wt;
                        pq.push({dis[i][v],v});
                    }
                }
            }
        }
        vector<double> res;
        for(auto &q : que){
            if(!mp.count(q[0]) || !mp.count(q[1])) res.push_back(-1.0);
            else if(dis[mp[q[0]]][mp[q[1]]]==DBL_MAX) res.push_back(-1.0);
            else res.push_back(dis[mp[q[0]]][mp[q[1]]]);
        }
        return res;
    }
};

// DFS Soln
class Solution {
public:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if(graph.find(start) == graph.end()){
            return -1;
        }
        
        if(graph[start].find(end) != graph[start].end()){
            return graph[start][end];
        }
        
        for(const auto& nei : graph[start]){
            if(find(visited.begin(), visited.end(), nei.first) != visited.end())
                continue;
            visited.insert(nei.first);
            double res;
            if((res = dfs(nei.first, end, graph, visited)) != -1){
                //optimization: runtime 4ms -> 0ms
                return graph[start][end] = graph[start][nei.first] * res;
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> quot;
        
        int N = equations.size();
        
        for(int i = 0; i < N; i++){
            const vector<string>& equation = equations[i];
            const string& num = equation[0], den = equation[1];
            const double& value = values[i];
            quot[num][num] = 1.0;
            quot[den][den] = 1.0;
            quot[num][den] = value;
            quot[den][num] = 1.0/value;
        }
        
        vector<double> ans;
        unordered_set<string> visited;
        
        for(const vector<string>& query : queries){
            const string& num = query[0], den = query[1];
            visited = {num};
            ans.push_back(dfs(num, den, quot, visited));
        }
        
        return ans;
    }
};