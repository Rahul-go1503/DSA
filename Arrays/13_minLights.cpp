/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/

// NOT solved -- IntriewBit - easy tag idk why easy, it seems to be hard for me :(
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;
    int curr = 0;
    int l= curr - B+1;
    int r= curr + B -1;
    int i=r;
    while(i>=0 && i>=l){
        if(A[i]!=1) i--;
        else if(A[i]==1){
            // cout<<"i is "<< j<<endl;
            cnt++;
            // cout<<"cnt is "<< cnt<<endl;
            curr=i;
            l= curr - B+1;
            r= curr + B -1;
            i=r;
        }
    }
    if(i<0 || i<l) return -1;
    return cnt;
}

int main(){
    vector<int> a = {0, 0, 0, 1, 0};
    cout<<solve(a,3)<<endl;
}

int solve(vector<int> &A, int B){
    int n = A.size();
    int s = 0, i = B-1, cnt = 0;
    while(i>=s && i<n){
        if(A[i]==1){
            cnt++;
            s = i;
            i = s + B; 
        }else{
            i--;
        }
    }
    return i == n ? cnt : -1;
}
