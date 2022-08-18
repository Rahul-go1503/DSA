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

string solve(int A) {
    string ans;
    ans.push_back(1+'0');
    // cout<<ans<<endl;
    for(int i=2;i<=A;i++){
        int carry =0;
        for(int j=0;j<ans.length();j++){
            int mul = (ans[j]-'0')*i+carry;
            ans[j] = mul%10+'0';
            carry = mul/10;
        // cout<<"here"<<endl;
        }
        while(carry){
            ans.push_back(carry%10+'0');
            carry = carry/10;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    // string s;
    // for(int i=0;i<ans.size();i++) s.push_back(ans[i]+'0');
    return ans;
}
int main(){
    int a = 100;
     solve(a);
}