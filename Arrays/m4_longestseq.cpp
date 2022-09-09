#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
/*
	Time Complexity: O(n)
	Space Complexity: O(n)
*/

class Solution{
  public:
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[arr[i]]++;
        auto i = m.begin();
        int mx=1;
        while(i!=m.end()){
            if(m.find((*i).first-1)!=m.end()){i++;continue;}
            int cnt = 1;
            int nxt = (*i).first+1;
            while(m.find(nxt)!=m.end()){
                nxt++;cnt++;
            }
            if(cnt>mx) mx = cnt;
            i++;
        }
        return mx;
    }
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> s(arr,arr+n);
        auto i = s.begin();
        int mx=1;
        while(i!=s.end()){
            if(s.find((*i)-1)!=s.end()){i++;continue;}
            int cnt = 1;
            int nxt = (*i)+1;
            while(s.find(nxt)!=s.end()){
                nxt++;cnt++;
            }
            if(cnt>mx) mx = cnt;
            i++;
        }
        return mx;
    }
    
    // o(nlogn),o(1) --TLE
    int findLongestConseqSubseq2(int arr[], int n)
    {
        set<int> s(arr,arr+n);
        auto i = s.begin(),j=i++;
        int prev=*i;
        int mx=1;
        while(j!=s.end()){
            int cnt = 1;
            while(j!=s.end() && *j==prev+1){
                prev=*j;j++;cnt++;
            }
            if(cnt>mx) mx = cnt;
            i=j;prev=*i;j++;
        }
        return mx;
    }
};