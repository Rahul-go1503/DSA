#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B, string C, int n, int m, int l)
{
	int lcs[n+1][m+1][l+1] = {};

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=l;k++){
				if(A[i-1]==B[j-1] && B[j-1]==C[k-1]){
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}
				else{
					int t1= max(lcs[i][j][k-1],lcs[i][j-1][k-1]);
					int t2= max(lcs[i][j-1][k],lcs[i-1][j][k]);
					int t3= max(lcs[i-1][j][k-1],lcs[i-1][j-1][k]);
					lcs[i][j][k] = max(t1,max(t2,t3));
				}
			}
		}
	}
	return lcs[n][m][l];
}

// gfg
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int solve(string &A, string &B, string &C, int i, int j, int k, vvvi &dp){
    if(i<0 || j<0 || k<0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    int res = 0;
    if(A[i] == B[j] && B[j] == C[k]){
        res = 1 + solve(A,B,C,i-1,j-1,k-1,dp);
    }
    else{
        int t1 = solve(A,B,C,i,j,k-1,dp);
        int t2 = solve(A,B,C,i,j-1,k,dp);
        int t3 = solve(A,B,C,i,j-1,k-1,dp);
        int t4 = solve(A,B,C,i-1,j,k,dp);
        int t5 = solve(A,B,C,i-1,j,k-1,dp);
        int t6 = solve(A,B,C,i-1,j-1,k,dp);
        res = max(max(t1,t2),max(max(t3,t4),max(t5,t6)));
    }
    return dp[i][j][k] = res;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vvvi dp(n1,vvi(n2,vi(n3,-1)));
    return solve(A,B,C,n1-1,n2-1,n3-1,dp);
}