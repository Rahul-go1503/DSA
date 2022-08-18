#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v){
    int n= v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<int> plusOne(vector<int>& digits) {
    int n= digits.size();
    int carry=1;
    for(int i=n-1;i>=0;i--){
        int digit= digits[i];
        int sum= digit+carry;
        digits[i]=sum%10;
        carry= sum/10;
    }
    if(carry!=0){
        digits.insert(digits.begin(),carry);
    }
    return digits;
    }
vector<int> plusOne2(vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i]++ < 9)
            return digits;
        digits[i] = 0;
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
} 
int main(){
    vector<int> digits = {1,9,9};
    vector <int> ans= plusOne2(digits);
    printVector(ans);
}