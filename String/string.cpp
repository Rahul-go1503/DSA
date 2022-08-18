/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s= "rahul";
    sort(s.begin(),s.end());

    char arr[] = "rahul";
    sort(arr,arr+strlen(arr));
    cout<<s<<endl;
    cout<<arr<<endl;


    const char * ptos = "hello";
    cout<<sizeof(*ptos)/sizeof(char) <<endl;

}