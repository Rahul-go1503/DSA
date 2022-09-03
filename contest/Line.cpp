/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/

/*
	Time Complexity: O()
	Space Complexity: O()

	Where 'N' is the total number of elements in the array.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string L;
        cin>>n>>L;
        long long line=0;
        for(int i=0;i<n;i++){
            if(L[i]=='R'){
                line+=n-(i+1);
            }else{
                line+=i;
            }
        }
        cout<<line<<endl;
        int i= (n-1)/2,j=i+1;
        if(n%2!=0)i--;
        bool onI = true;
        for(int k=1;k<=n;k++){
            cout<<k<<endl;
            while(i>=0 || j<n){
                if(i>=0 && L[i]=='L' && onI){
                    line= line - i + n-(i+1);
                    i--;
                    onI = false;
                    cout<<line<<" ";
                    break;
                }else if(j<n && L[j]=='R') {
                    line= line - n+(j+1)+j;
                    j++;
                    onI = true;
                    cout<<line<<" ";
                    break; 
                }else{
                    if(i<0){i=0;continue;onI=false;}
                    if(j==n){j=n-1;continue;}
                    i--;j++;
                }
            }
            if(i==0 && j==n-1) cout<<line<<" ";
        }
        cout<<endl;
    }
}