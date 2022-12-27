/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> s(a,a+n);
        for(int i=0;i<m;i++) s.insert(b[i]);
        return s.size();
    }
};

// idk why it is not working properly ~~ copy paste me glitch tha Accepted successfully (:

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        sort(a,a+n);
        sort(b,b+m);
        int cnt = 0 ,i = 0, j=0;
        while(i<n && j<m){
            if(a[i]<b[j]) i++;
            else if(a[i]>b[j]) j++;
            else i++,j++;
            cnt++;
            
            while(i>0 && i<n && a[i]==a[i-1]) i++;
            while(j>0 && j<m && b[j]==b[j-1]) j++;
        }
        while(i<n){
            i++,cnt++;
            while(i<n && a[i]==a[i-1]) i++;
        }
        while(j<m){
            j++,cnt++;
            while(j<m && b[j]==b[j-1]) j++;
        }
        return cnt;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    Solution s;
    return s.doUnion(a,n,b,m);
}