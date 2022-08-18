/*********************************************************************************************

Question :


Notes :
We don't have to check whether y*10 + x%10 will overflow is because if y*10+x%10 will overflow, then y*10 must overflow or the input number is not a vaild input.
Welcome for any discussion.
**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int reverse(int x) {
        int ans=0;
        int num = abs(x);
        while(num>0){
            // cout<<"enter "<<ans<<endl;
            // cout<<(INT_MAX-x%10)<<endl;
            // cout<<INT_MIN<<endl;
            // cout<<(INT_MIN-x%10)<<endl;
            if(ans>(INT_MAX-num%10)/10) return 0;
            ans=ans*10+num%10;
            num=num/10;
        }
        return x>0?ans:-ans;
    }
class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x){
            if(y>INT_MAX/10 || y<INT_MIN/10) return 0;
            y=y*10 +x%10;
            x=x/10;
        }
        return y;
    }
};
int main()
{
    cout<<"ans is "<<reverse(-1463847412)<<endl;
}