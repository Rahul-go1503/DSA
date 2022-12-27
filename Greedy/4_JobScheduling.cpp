#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// O(n2),O(n); Accepted
class Solution 
{
    static bool cmp(Job j1, Job j2){
        // if(j1.profit == j2.profit) return j1.dead < j2.dead;
        return j1.profit > j2.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int jbcnt = 0, profit = 0;
        int vis[n] = {0};
        for(int i=0;i<n;i++){
            for(int j = min(n,arr[i].dead)-1;j>=0;j--){
                if(!vis[j]){
                    vis[j] = 1;
                    jbcnt++;
                    profit += arr[i].profit;
                    break;
                }
            }
            
        }
        return {jbcnt,profit};
    } 
};