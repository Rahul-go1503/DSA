#include <bits/stdc++.h>
using namespace std;

// TC - 2*nlogn + 2*n;
// from striver
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // not much intutive but here we are only intersed in timing of the train
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
        // first train will occupy one plt
    	int mx = 1 , occ_plt = 1;
    	for(int i=1,j=0;i<n;){
            // next train will occupy diff plt
    	    if(arr[i]<=dep[j]) occ_plt++,i++;

            // prev train departed, no of occ_plt will decrease
    	    else{
    	        occ_plt--, j++;
    	    }
    	    mx = max(mx,occ_plt);
    	}
    	return mx;
    }
};

// by pq - code later

// wrong approach
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>> trains;
    	for(int i=0;i<n;i++) trains.push_back({dep[i],arr[i]});
    	sort(trains.begin(),trains.end());
    	
    	bool vis[n] = {0};
    	int plt = 0;
    	
    	for(int i=0;i<n;i++){
    	    if(vis[i]) continue;
    	    vis[i] = 1 , plt++;
    	    
    	    for(int j = i+1,s=i;j<n;j++){
    	        if(!vis[j] && trains[j].second > trains[s].first){
    	            vis[j] = 1;
    	            s = j;
    	        }
    	       // else if(!vis[j]) break;
    	    }
    	}
    	return plt;
    }
};


