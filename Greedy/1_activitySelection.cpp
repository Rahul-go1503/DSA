#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class Solution
{
    bool static cmp(vi &a, vi &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<int> arr[n];
        for(int i=0;i<n;i++) arr[i]={start[i],end[i]};
        sort(arr,arr+n,cmp);
        int act = 1, ed = arr[0][1];
        for(int i=1;i<n;i++){
            if(ed<arr[i][0]) act++,ed = arr[i][1];
        }
        return act;
    }
};