#include <bits/stdc++.h> 
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()
stack<int> pushAtBottom(stack<int>& st, int x) 
{
    if(st.empty()){
        st.push(x);
        return st;
    }
    int num = st.top();
    st.pop();
    pushAtBottom(st,x);
    st.push(num);
    return st;
}
