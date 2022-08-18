#include<bits/stdc++.h>
using namespace std;
string binaryShopping(string S, int P)
{
    // Write your code here.
	int cnt=0;
	int e= S.length()-1;
	while(cnt!=2 && e>=0){
        if(e==0 && S[e]=='0'){
            S[e]='1';
            cnt++;
        }else if(e==0 && S[e]=='1'){
            S[e]='0';
            cnt++;
        }
		else if(S[e]=='1'){
		S[e--]='0';
		cnt++;
		}else e--;
	}
	return S;
}
int main(){
    string S="10111";
    cout<<binaryShopping(S,3);
}