#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string str, int n){
    string ans;
    int index = 0;
    for (int i = 0; i < n; i++){
        int j;
        for (j = 0; j < i; j++){
            if (str[i] == str[j]){
                break;
            }
        }
        if (j == i){
            ans.push_back(str[i]);
            index++;
        }
    }
    return ans;
}

int main()
{
    string str = "aaaaaaaaaaaaaaavvvvvvvvvvvvv";
    int n = str.length();
    cout << removeDuplicate(str, n);
    return 0;
}