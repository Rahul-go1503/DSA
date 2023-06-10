#include<bits/stdc++.h>
using namespace std;

int func(char c,string s,string &t){
    if(s.size()==t.size()) return 0;
    bool b=true;
    int ans=1;
    for(auto it=s.begin();it!=s.end();){
        if(b && *it!=c){
            b=false;
            it=s.erase(it);
        }
        else{
            b=true;
            it++;
        }
    }
    ans+=func(c,s,t);
    return ans;

}

int main()
 {
 	// #ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    //   freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    // #endif
    	//A=65,a=97,0=48
      int cases;
      cin>>cases;
      while(cases--){
        string s;
        cin>>s;
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[int(s[i])-97]++;
        }
        int ele=*max_element(count.begin(),count.end());
        vector<char> c;
        for(int i=0;i<26;i++){
            if(count[i]==ele){
                c.push_back(char(97+i));
            }
        }
        int ans=1e9;
        string t;
        for(int i=0;i<c.size();i++){
            
            for(int j=0;j<count[int(c[i])-97];j++){
                t.push_back(c[i]);
            }
            ans=min(ans,func(c[i],s,t));
            t.clear();
        }
        cout<<ans<<endl;
      }
 	return 0;
 }
