#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
stack<int> st;
int size= temperatures.size();
vector<int> ans(size);
for(int i=0;i<size;i++){
    while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
        ans[st.top()]=(i-st.top());
        st.pop();
    }
    st.push(i);
}
return ans;
}


// vector<int> dailyTemperatures(vector<int>& temperatures) {
// int size= temperatures.size();
// vector<int> ans(size);
// int k=0;
// for(int i=1;i<size;i++){
//    int j=i-1;
//    while(j>=k&&temperatures[j]<temperatures[i]){
//     ans[j]=i-j;
//     j--;
//     k++;
//    }
// }
// return ans;
// }

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0) j = res[j] + j;
            else j = temperatures.size();
        }
        // either j == size || temperatures[j] > temperatures[i]
        if (j < temperatures.size()) res[i] = j - i;
    }
    return res;
}