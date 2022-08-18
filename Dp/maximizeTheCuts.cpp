/*********************************************************************************************

Question : 221. Maximal Square


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //babbar
    int solveRec(int n ,int x, int y, int z){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        int a = solveRec(n-x,x,y,z)+1;
        int b= solveRec(n-y,x,y,z)+1;
        int c =solveRec(n-z,x,y,z) +1;
        return max(a,max(b,c));
    }
    int solveMemL(int n ,int x, int y, int z,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        int a = solveRec(n-x,x,y,z)+1;
        int b= solveRec(n-y,x,y,z)+1;
        int c =solveRec(n-z,x,y,z) +1;
        return dp[n] =  max(a,max(b,c));
    }
    int solveTabL(int n ,int x, int y, int z){
        vector<int> dp (n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(i-x>=0)
                dp[i] = max(dp[i],dp[i-x]+1);
            if(i-y>=0)
                dp[i] = max(dp[i],dp[i-y]+1);
            if(i-z>=0)
                dp[i] = max(dp[i],dp[i-z]+1);
        }
        return dp[n]<0 ? 0 : dp[n];
    }
    int solveMem(int n, int x, int y, int z,vector<int>& dp){
        if(n==0) return 0;
        cout<<"enter here for n= " << n << endl;
        if(n<0){
        cout<<"enter here" <<" "<< INT_MIN << endl;
        return INT_MIN;
        }
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MIN;
        int tempx = solveMem(n-x,x,y,z,dp);
        int tempy = solveMem(n-y,x,y,z,dp);
        int tempz = solveMem(n-z,x,y,z,dp);
        int temp = max(tempx,max(tempy,tempz));
        cout<<tempx<<" "<<tempy<<" "<<tempz<<endl;
        if(temp!=INT_MIN)
            ans = max(ans,1+temp);
        return dp[n]=ans;
    }

    int solveTab(int n, int x, int y, int z){
        vector<int> dp (n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int tempX=INT_MIN,tempY=INT_MIN,tempZ=INT_MIN;
            if(i-x>=0)
                tempX = dp[i-x];
            if(i-y>=0)
                tempY = dp[i-y];
            if(i-z>=0)
                tempZ = dp[i-z];
            int temp = max(tempX,max(tempY,tempZ));
            if(temp!=INT_MIN)
                dp[i] = max(dp[i],1+temp);
        }
        return dp[n]==INT_MIN ? 0 : dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
    vector<int> dp(n+1,-1);
    int ans = solveMem(n,x,y,z,dp);
    return ans == INT_MIN ? 0 : ans;
    }
};