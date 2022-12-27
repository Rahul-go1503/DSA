#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int num)
{
    int s=1;
    int e= num;
    // while(s<=e){
    //     int mid = s+ (e-s)/2;
    //     cout<<mid<<"\n";
    //     if(mid==(1LL*num)/mid){
    //         cout<<" true : ";
    //     return true;
    //     } 
    //     else if(mid<(1LL*num)/mid) s= mid+1;
    //     else e=mid-1;
    // }
    while(s<=e){
        int mid = s+ (e-s)/2;
        cout<<mid<<" ";
        long long int sqre= 1LL*mid*mid;
        cout<<sqre<<"\n";
        if(sqre==num) return true;
        else if(sqre<num) s= mid+1;
        else e=mid-1;
    }
    cout<<endl;
    return false;
}
int main(){
    int num = 98765432;
    cout<<isPerfectSquare(num)<<endl;
}
/*
This solution makes use of the fact that all square numbers are sum of odd numbers starting from 1.
For ex :
1 = 1
1+3 = 4
1 + 3 + 5 = 9
1 + 3 + 5 + 7 = 16
.... and so on
 */
bool isPerfectSquare(int num) {
        int i=1;
        while(num>0){
            num -= i;      //Subtracting odd number from num and updating num
            i +=2;         // Updating i to the next odd number
            if(!num) return true;
        }
        return false;
}