#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(), SC - O()
void insert(stack<int>&st, int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    insert(st,x);
    st.push(num);
    
}
void sortStack(stack<int> &st)
{
	if(st.empty()) return;
    int num = st.top();
    st.pop();
    sortStack(st);
    insert(st,num);
}