/*********************************************************************************************

Question :


Notes :

**********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


int main(){
    // char arr[] = "rahul";
    // or
    char arr[] = {'r','a','h','u','l','\0'};

    cout<<strlen(arr)<<endl; // 5

    char s1[10] = "Hello";
 
    // return length of s1
    cout << strlen(s1) << endl;
 
    char s2[50];
    cout << strlen(s2) << endl;
 
    // copies s1 into s2
    // strcpy(s2, s1);
    // cout << s2 << endl;
 
    // char s3[10] = "World";
 
    // // concatenates s3 into s2
    // strcat(s2, s3);
    // cout << s2 << endl;
 
    // char s4[50] = "HelloWorld";
 
    // // return 0 if s2 and s4 are equal.
    // if (strcmp(s2, s4) == 0)
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
 
    // char s5[30];
 
    // // copies first 5 chars of s4 into s5
    // strncpy(s5, s4, 5);
    // cout << s5 << endl;
 
    // char target[10] = "Hello";
 
    // // search for target string in s4
    // if (strstr(s4, target) != NULL)
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
 
    return 0;
}