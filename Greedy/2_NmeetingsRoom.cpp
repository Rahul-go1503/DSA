#include <bits/stdc++.h>
using namespace std;

struct node{
    int s,e,i; // storing if we have to answer the meetings number also
};

bool cmp(node n1, node n2){
    return n1.e < n2.e;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<node> mets(n);
        for(int i=0;i<n;i++) mets[i] = {start[i],end[i],i+1};
        sort(mets.begin(),mets.end(),cmp);
        
        int res = 1;
        for(int i=1, k = 0;i<n;i++){
            if(mets[i].s > mets[k].e) k = i,res++;
        }
        return res;
    }
};