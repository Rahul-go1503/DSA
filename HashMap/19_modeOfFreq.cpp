#include <bits/stdc++.h>
using namespace std;

// codechef
// https://www.codechef.com/problems/MODEFREQ
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++) cin>>arr[i];
    	
    	unordered_map<int,int> freq;
    	for(auto &num : arr) freq[num]++;
    	
    	unordered_map<int,int> freqOfFreq;
    	for(auto &p : freq) freqOfFreq[p.second]++;
    	
    	int res = 0 , resFreq = 0;
    	for(auto &p : freqOfFreq){
    	    if(p.second == resFreq && p.first < res) res = p.first;
    	    else if(p.second > resFreq) resFreq = p.second , res = p.first;
    	}
    	cout<<res<<endl;
	}
}
