#include <bits/stdc++.h>
using namespace std;
/*********************************************************************************************

Question :

**********************************************************************************************/

// TC - O(n), SC - O(n/2)
void deleteMiddle(stack<int>&in, int N){
   stack<int> temp;
    int cnt = 0;
    while(cnt<N/2){
        temp.push(in.top());
        in.pop();
        cnt++;
    }
    in.pop();
    while(cnt--){
        in.push(temp.top());
        temp.pop();
    }
}