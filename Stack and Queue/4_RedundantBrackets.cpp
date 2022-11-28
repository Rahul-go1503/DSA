#include <bits/stdc++.h> 
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()
// ignore lowercasr letters in stream
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    bool found = false;
    for(int i =0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z') continue;
        if(s[i]==')'){
            bool isRedundant = true;
            while(st.top()!='('){
                isRedundant = false;
                st.pop();
            }
            st.pop();
            if(isRedundant) return true;
        }else st.push(s[i]);
    }
    return false;
}
