#include <bits/stdc++.h>
using namespace std;


/* Now let's perform binary addition it's very similar to the decimal addition that we do. In decimal what we do we add 2 numbers & if it goes beyond 9 we take a carry. And here also we have a number in range 0 - 1, 2 values over here & in Decimal range is 0 - 9, 10 values are there. So, in binary what it means is if result more than 1, there is a carry otherwise no carry.


a = a + "xy" is O(N) while a += "xy" is O(1) (amortized).

a = a + "xy" creates a copy of a, appends "xy" and then assigns it back to a.

a += "xy" just appends "xy" to a.
*/
// Day 9
string binTodec(string s){
    string ans=0;
    for(int i=s.length()-1;i>=0;i--){
        char bit=s[i];
        ans.push_back(bit);
    }
    reverse(ans.begin(),ans.end());
    return ans;
} 
string decTobin(int n){
    string ans;
    while(n>0){
        int bit = n&1;
        ans.push_back(bit+'0');
        n=n>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string addBinary(string a, string b) {
        int na= a.length()-1;
        int nb= b.length()-1;
        string ans;
        int carry=0;
        while(na>=0&&nb>=0){
            int ca= a[na]-'0';
            int cb= b[nb]-'0';
            if(ca+cb+carry==3){
                ans.push_back('1');
                carry=1;
            }
            else if(ca+cb+carry==2){
                ans.push_back('0');
                carry=1;
            }else{
                ans.push_back(ca+cb+carry+'0');
                carry=0;
            }
            na--;nb--;
        }
            // cout<<"1st "<<ans<<endl;
        while(na>=0){
            int ca= a[na]-'0';
            if(ca+carry==2){
                ans.push_back('0');
                carry=1;
            }else{
                ans.push_back(ca+carry+'0');
                carry=0;
            }
            na--;
        }
            // cout<<"2nd "<<ans<<endl;
        while(nb>=0){
            int cb= b[nb]-'0';
            cout<<"cb "<<cb<<"carr "<<carry<<endl;
            if(cb+carry==2){
                ans.push_back('0');
                cout<<"3.1 "<<ans<<endl;
                carry=1;
            }else{
                ans.push_back(cb+carry+'0');
                cout<<"3.2 "<<ans<<endl;
                carry=0;
            }
            nb--;
            // cout<<"3rd "<<ans<<endl;
        }
        if(carry) ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
    }

string addBinary2(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        //  res = to_string(sum % 2) + res;
        reverse(res.begin(), res.end());
        return res;
    }




    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    string s1="1",s2="111";
    // cout<<"enter\n";
    // cin>>s1>>s2;
    cout<<" final ans is : "<<addBinary(s1,s2)<<endl;

}