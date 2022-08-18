#include<bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
    string ans ="";
    vector<char>ch ={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> val = {1, 5, 10, 50, 100, 500, 1000};
    for(int i=val.size()-1;i>=0;i-- && num>0){
        int cnt=0;
        while(num>=val[i] && num>0){
            num-=val[i];
            cnt++;
            if(cnt<4) ans.push_back(ch[i]);
            else{
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
                cout<<ans.empty()<<endl;
                cout<<ans.back()<<endl;
                if(!ans.empty()&&(ans.back()==ch[1]||ans.back()==ch[3]||ans.back()==ch[5])){
                ans.pop_back();
                ans.push_back(ch[i]);
                ans.push_back(ch[i+2]);

                }else{ 
                // ans.pop_back();
                ans.push_back(ch[i]);
                ans.push_back(ch[i+1]);
                }
            }
        }
    }
    return ans;
}
int main(){
    int num=44;
    cout<<"ans is : "<<intToRoman(num)<<endl;
}