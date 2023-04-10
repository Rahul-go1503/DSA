#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	unordered_map<int,vector<int>> mp;
    	for(int i=0;i<n;i++){
    	    if(mp.count(a[i])){
    	        mp[a[i]] = {++mp[a[i]][0], i-mp[a[i]][2] + 1, mp[a[i]][2]};
    	    }else{
    	        mp[a[i]] = {1, 1, i};
    	    }
    	   // cout<<a[i]<<" "<<mp[a[i]][0]<<" "<<mp[a[i]][1]<<" "<<mp[a[i]][2]<<endl;
    	}
    	int mxFreq = 0, subSize = 0, idx = n, mxElem = 0;
    	for(auto &it : mp){
    	    if(it.second[0] == mxFreq && it.second[1] == subSize && it.second[2] < idx){
    	        mxElem = it.first;
    	        idx = it.second[2];
    	    }
    	    else if(it.second[0] == mxFreq && it.second[1] < subSize){
    	        mxElem = it.first;
    	        subSize = it.second[1];
    	        idx = it.second[2];
    	    }else if(it.second[0] > mxFreq){
    	        mxElem = it.first;
    	        mxFreq = it.second[0];
    	        subSize = it.second[1];
    	        idx = it.second[2];
    	    }
    	}
    	
    // 	cout<<mxElem<<" "<<mxFreq<<" "<<subSize<<" "<<idx<<endl;
    	vector<int> subarr;
    	for(int i=idx;i<n && mxFreq;i++){
    	    subarr.push_back(a[i]);
    	    if(a[i] == mxElem) mxFreq--;
    	}
    	
    	return subarr;
    }
};